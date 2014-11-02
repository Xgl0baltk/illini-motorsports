/*
 * Shift Lights Header
 *
 * File Name:   ShiftLights.h
 * Processor:   PIC18F46K80
 * Compiler:    Microchip C18
 * Author:      Andrew Mass
 * Author:      George Schwieters
 * Created:     2014-2015
 */

#ifndef MAIN_H
#define MAIN_H

/*
 * Address Bytes
 */

#define TERM_LAT    LATCbits.LATC6

#define RED0_LAT    LATAbits.LATA2
#define GREEN0_LAT  LATAbits.LATA1
#define BLUE0_LAT   LATAbits.LATA0

#define RED1_LAT    LATDbits.LATD0
#define GREEN1_LAT  LATCbits.LATC3
#define BLUE1_LAT   LATCbits.LATC2

#define RED2_LAT    LATDbits.LATD3
#define GREEN2_LAT  LATDbits.LATD2
#define BLUE2_LAT   LATDbits.LATD1

#define RED3_LAT    LATCbits.LATC7
#define GREEN3_LAT  LATCbits.LATC5
#define BLUE3_LAT   LATCbits.LATC4

#define RED4_LAT    LATDbits.LATD6
#define GREEN4_LAT  LATDbits.LATD5
#define BLUE4_LAT   LATDbits.LATD4

#define RED0_TRIS   TRISAbits.TRISA2
#define GREEN0_TRIS TRISAbits.TRISA1
#define BLUE0_TRIS  TRISAbits.TRISA0

#define RED1_TRIS   TRISDbits.TRISD0
#define GREEN1_TRIS TRISCbits.TRISC3
#define BLUE1_TRIS  TRISCbits.TRISC2

#define RED2_TRIS   TRISDbits.TRISD3
#define GREEN2_TRIS TRISDbits.TRISD2
#define BLUE2_TRIS  TRISDbits.TRISD1

#define RED3_TRIS   TRISCbits.TRISC7
#define GREEN3_TRIS TRISCbits.TRISC5
#define BLUE3_TRIS  TRISCbits.TRISC4

#define RED4_TRIS   TRISDbits.TRISD6
#define GREEN4_TRIS TRISDbits.TRISD5
#define BLUE4_TRIS  TRISDbits.TRISD4

/*
 * Data Bytes
 */

// Colors
#define NONE       0b000
#define RED        0b001
#define GREEN      0b010
#define BLUE       0b100
#define RED_GREEN  RED | GREEN
#define RED_BLUE   RED | BLUE
#define GREEN_BLUE GREEN | BLUE
#define RGB        RED | GREEN | BLUE

// Rev range
#define REV_RANGE_1     8000
#define REV_RANGE_2     9000
#define REV_RANGE_3     10000
#define REV_RANGE_4     11000
#define REV_RANGE_5     11500
#define REV_RANGE_LIMIT 12500

// Custom color choices
#define REV_COLOR       BLUE
#define REV_LIMIT_COLOR RED

#define OP_THRESHOLD_L 160
#define OP_THRESHOLD_H 250
#define OT_THRESHOLD 2100
#define ET_THRESHOLD 1150
#define RPM_THRESHOLD_H 4000
#define RPM_THRESHOLD_L 1000

#define BLINK_TIME 200

typedef char bool;
#define false 0
#define true 1

/*
 * Method Headers
 */

void high_isr(void);
void set_led_to_color(unsigned char led, unsigned char color);
void set_all(unsigned char color);
void set_lights(unsigned char max);
void startup(int currentTime);
void excess(int type);
void checkVolts();
int length(int array[]);
void multi_led_color(int led[], unsigned char color, int size);
void sleep(int seconds, int milliAmount);
bool checkStatus();
bool timeout(bool sleep);
bool checkEngineTemp();
bool checkOilTemp();
bool checkOilPressure();
bool checkBatteryVolts();
bool lastAccessWithinMsgInterval(int i);
void blink_all(int numOfTimes, unsigned char color);
void alternate_blink(int ledSet1[], int size1, unsigned char color1, int ledSet2[], int size2, unsigned char color2, int numOfTimes);
void display();
void errorDisplay(int error);


#endif
