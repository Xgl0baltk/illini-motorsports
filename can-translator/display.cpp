/**
 * @file display.cpp
 * Implementation of the AppDisplay class.
 *
 * @author Andrew Mass
 * @date Created: 2014-06-24
 * @date Modified: 2014-07-30
 */
#include "display.h"

AppDisplay::AppDisplay() : QWidget() {
  this->successful = false;
  this->resize(WIDTH, HEIGHT);
  this->setWindowTitle("Illini Motorsports CAN Translator - 2015");
  this->setLayout(&layout);

  connect(&data, SIGNAL(error(QString)), this, SLOT(handleError(QString)));
  connect(&data, SIGNAL(progress(int)), this, SLOT(updateProgress(int)));
  connect(&config, SIGNAL(error(QString)), this, SLOT(handleError(QString)));

  layout.addLayout(&layout_headers);

  QFont font_header("Helvetica", 20, QFont::Bold);
  QFont font_subheader("Helvetica", 15);
  QFont font_message("Helvetica", 15, QFont::Black);
  QFont font_channel("Helvetica", 11);

  lbl_header.setText("Illini Motorsports CAN Translator - 2015");
  lbl_header.setFont(font_header);
  lbl_header.setStyleSheet("QLabel { color: black; }");
  lbl_header.setAlignment(Qt::AlignCenter);
  layout_headers.addWidget(&lbl_header, 1);

  lbl_subheader.setText("Created By: Andrew Mass");
  lbl_subheader.setFont(font_subheader);
  lbl_subheader.setAlignment(Qt::AlignCenter);
  layout_headers.addWidget(&lbl_subheader, 1);

  lbl_keymaps.setText("[c] Convert File     [a] Select All     [n] Select None     [q] Quit");
  lbl_keymaps.setFont(font_subheader);
  lbl_keymaps.setAlignment(Qt::AlignCenter);
  layout_headers.addWidget(&lbl_keymaps, 1);

  btn_read.setText("Select File to Convert");
  layout.addWidget(&btn_read, 1);

  btn_select_all.setText("Select All Channels");
  layout_selects.addWidget(&btn_select_all, 1);

  btn_select_none.setText("Select No Channels");
  layout_selects.addWidget(&btn_select_none, 1);

  layout.addLayout(&layout_selects);

  layout.addWidget(&bar_convert, 1);

  map<unsigned short, Message> messages = config.getMessages();
  if(messages.size() > 0) {
    this->successful = true;
  }

  table.setRowCount(messages.size());
  table.setColumnCount(7);

  QStringList headers;
  headers << "ID" << "L" << "BE" << "Channel 0" << "Channel 1" << "Channel 2" << "Channel 3";
  table.setHorizontalHeaderLabels(headers);

  table.horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
  table.horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
  table.horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
  table.horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
  table.horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
  table.horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
  table.horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
  table.verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  int i = 0;
  typedef map<unsigned short, Message>::iterator it_msg;
  for(it_msg msgIt = messages.begin(); msgIt != messages.end(); msgIt++) {
    Message msg = msgIt->second;

    QTableWidgetItem* item_id = new QTableWidgetItem(QString::number(msg.id, 16));
    item_id->setFlags(Qt::NoItemFlags);
    table.setItem(i, 0, item_id);

    QTableWidgetItem* item_dlc = new QTableWidgetItem(QString::number(msg.dlc));
    item_dlc->setFlags(Qt::NoItemFlags);
    table.setItem(i, 1, item_dlc);

    QTableWidgetItem* item_ibe = new QTableWidgetItem(msg.isBigEndian ? "T" : "F");
    item_ibe->setFlags(Qt::NoItemFlags);
    table.setItem(i, 2, item_ibe);

    int j = 0;
    typedef QVector<Channel>::iterator it_chn;
    for(it_chn chnIt = msg.channels.begin(); chnIt != msg.channels.end(); chnIt++) {
      Channel chn = *chnIt;
      QTableWidgetItem* item = new QTableWidgetItem("     " + chn.title + "<" + chn.units + ">" + " isS: " + (chn.isSigned ? "T" : "F") +
        " S: " + QString::number(chn.scalar) + " O: " + QString::number(chn.offset));
      item->setFlags(Qt::NoItemFlags);
      item->setFont(font_channel);
      table.setItem(i, 3 + j, item);

      QCheckBox* box = new QCheckBox();
      box->setFocusPolicy(Qt::NoFocus);
      box->setChecked(!(chn.title.compare("Unused") == 0 || chn.title.compare("Rsrvd") == 0));
      box->setStyleSheet("QCheckBox:hover { background-color: rgba(255, 255, 255, 0); }");
      table.setCellWidget(i, 3 + j, box);
      j++;
    }

    while(j < 4) {
      QTableWidgetItem* item = new QTableWidgetItem();
      item->setFlags(Qt::NoItemFlags);
      table.setItem(i, 3 + j, item);
      j++;
    }

    i++;
  }

  table.setFocusPolicy(Qt::NoFocus);
  table.setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
  table.setMinimumHeight(550);
  table.setMinimumWidth(1400);
  table.setFont(font_message);
  table.resizeColumnsToContents();
  table.show();
  layout.addWidget(&table, 1);

  connect(&btn_select_all, SIGNAL(clicked()), this, SLOT(selectAll()));
  connect(&btn_select_none, SIGNAL(clicked()), this, SLOT(selectNone()));
  connect(&btn_read, SIGNAL(clicked()), this, SLOT(readData()));
}

map<unsigned short, vector<bool> > AppDisplay::getEnabled() {
  map<unsigned short, vector<bool> > enabled;
  map<unsigned short, Message> messages = config.getMessages();

  for(int i = 0; i < table.rowCount(); i++) {
    bool conv;
    vector<bool> msgEnabled;
    Message msg = messages[table.item(i, 0)->text().toUInt(&conv, 16)];

    int j = 0;
    typedef QVector<Channel>::iterator it_chn;
    for(it_chn chnIt = msg.channels.begin(); chnIt != msg.channels.end(); chnIt++) {
      msgEnabled.push_back(((QCheckBox*) table.cellWidget(i, 3 + j))->isChecked());
      j++;
    }
    enabled[msg.id] = msgEnabled;
  }

  return enabled;
}

void AppDisplay::selectAll() {
  selectBoxes(true);
}

void AppDisplay::selectNone() {
  selectBoxes(false);
}

void AppDisplay::selectBoxes(bool checked) {
  map<unsigned short, Message> messages = config.getMessages();
  bool conv;
  for(int i = 0; i < table.rowCount(); i++) {
    Message msg = messages[table.item(i, 0)->text().toUInt(&conv, 16)];

    for(int j = 0; j < msg.channels.size(); j++) {
      ((QCheckBox*) table.cellWidget(i, 3 + j))->setChecked(checked);
    }
  }
}

void AppDisplay::readData() {
  btn_read.setEnabled(false);
  btn_select_all.setEnabled(false);
  btn_select_none.setEnabled(false);

  data.filename = QFileDialog::getOpenFileName(this, "Open File", ".", "Files (*.*)");
  data.enabled = this->getEnabled();
  if(data.writeAxis() && data.readData()) {
    QMessageBox::information(this, "Conversion Completed!", "Output File: ./out.txt");
  }

  btn_read.setEnabled(true);
  btn_select_all.setEnabled(true);
  btn_select_none.setEnabled(true);
}

void AppDisplay::handleError(QString error) {
  QMessageBox::critical(this, "Critical Error", error);
}

void AppDisplay::updateProgress(int progress) {
  bar_convert.setValue(progress);
}

void AppDisplay::keyPressEvent(QKeyEvent* e) {
  // Opens file conversion dialog.
  if(e->text() == "c") {
    btn_read.click();
  }

  // Selects all channel checkboxes.
  if(e->text() == "a") {
    btn_select_all.click();
  }

  // Selects no channel checkboxes.
  if(e->text() == "n") {
    btn_select_none.click();
  }

  // Quits the application.
  if(e->text() == "q") {
    QApplication::quit();
  }
}