/******************************************************************************
 *
 *              ECAN C Library Code Configuration Header
 *
 ******************************************************************************
 * FileName:        ECAN_shift_lights_config.h
 * Dependencies:	none
 * Processor:       PIC18F46K80
 * Complier:        Microchip C18

*******************************************************************************
	USER REVISON HISTORY
	DO NOT use Microchip Maestro Software to regenerate this file!

// 02/12/13 - set all bit timing to get 1Mbps data rate and ~80% sample point w/
//          PLL as clock source (64MHz)
// 02/14/13 - added ECAN_CLOCK_SOURCE_MODE define
//          - added PIE5 IF enable defines
//			- added interrupt priority defines
// 03/08/13 - added filters to stop the ECAN module from recieving messages
// 11/28/13 - added defines for individual buffer interrupts
//

*******************************************************************************/


#ifndef ECANCONFIG_H
#define ECANCONFIG_H

#include "CAN.h"

//
//
// ECAN Routine Mode:
// Possible values are ECAN_LIB_MODE_FIXED, ECAN_LIB_MODE_RUN_TIME
//   Use ECAN_LIB_MODE_FIXED if run-time selection of mode is not required.
//   Use ECAN_LIB_MODE_RUN_TIME if run-time selection is required.
//   Refer to datasheet for information about the Window Address bits
//   FIFO mode can be either FOUR or ONE
#define ECAN_LIB_MODE_VAL ECAN_LIB_MODE_FIXED
#define ECAN_FIFO_MODE 0
//
// ECAN Functional Mode to be used in ECANInitialize().
// Possible values are ECAN_MODE_0, ECAN_MODE_1, ECAN_MODE_2
#define ECAN_FUNC_MODE_VAL ECAN_MODE_2
//
// ECAN interrupt enables
#define ECAN_RECIEVED_ERROR_IF_MODE DISABLE
#define ECAN_WAKEUP_IF_MODE DISABLE
#define ECAN_BUS_ERROR_IF_MODE DISABLE
#define ECAN_TXBn_IF_MODE DISABLE
#define ECAN_TXB1_IF_MODE DISABLE
#define ECAN_TXB0_IF_MODE DISABLE
#define ECAN_RXBn_IF_MODE DISABLE
#define ECAN_FIFO_IF_MODE DISABLE
#define ECAN_BIE_BX0 ENABLE
#define ECAN_BIE_BX1 ENABLE
#define ECAN_BIE_B0 ENABLE
#define ECAN_BIE_B1 DISABLE
#define ECAN_BIE_B2 DISABLE
#define ECAN_BIE_B3 DISABLE
#define ECAN_BIE_B4 DISABLE
#define ECAN_BIE_B5 DISABLE
//
// ECAN interrupt priority configurations
#define ECAN_RECIEVED_ERROR_PRIORITY PR_HIGH
#define ECAN_WAKEUP_PRIORITY PR_HIGH
#define ECAN_BUS_ERROR_PRIORITY PR_HIGH
#define ECAN_TXBn_PRIORITY PR_HIGH
#define ECAN_TXB1_PRIORITY PR_HIGH
#define ECAN_TXB0_PRIORITY PR_HIGH
#define ECAN_RXBn_PRIORITY PR_HIGH
#define ECAN_FIFO_PRIORITY PR_HIGH
//
// Mode to leave ECAN after ECANInit.
// Possible values are ECAN_INIT_NORMAL, ECAN_INIT_CONFIGURATION, ECAN_INIT_LOOPBACK, ECAN_INIT_DISABLE
#define ECAN_INIT_MODE ECAN_INIT_NORMAL
//
// SJW value - Value must be between 1-4 inclusive.
#define ECAN_SJW_VAL 1
//
// BRP value - Value must be between 1-64 inclusive.
#define ECAN_BRP_VAL 2
//
// PHSEG1 value - Value must be between 1-8 inclusive.
#define ECAN_PHSEG1_VAL 4
//
// PHSEG2 value - Value must be between 1-8 inclusive.
#define ECAN_PHSEG2_VAL 3
//
// PROPSEG value - Value must be between 1-8 inclusive.
#define ECAN_PROPSEG_VAL 8
//
// Use freely progrmable PHSEG2 or calculated value.
#define ECAN_PHSEG2_MODE_VAL ECAN_PHSEG2_MODE_PROGRAMMABLE
//
// Bus Sample Mode
#define ECAN_BUS_SAMPLE_MODE_VAL ECAN_BUS_SAMPLE_MODE_THRICE
//
// Wakeup Mode
#define ECAN_WAKEUP_MODE_VAL ECAN_WAKEUP_MODE_DISABLE
//
// Filter Mode
#define ECAN_FILTER_MODE_VAL ECAN_FILTER_MODE_DISABLE
//
// CANTX1 Drive Mode
#define ECAN_TXDRIVE_MODE_VAL ECAN_TXDRIVE_MODE_VDD
//
// CANTX2 pin mode
#define ECAN_TX2_MODE_VAL ECAN_TX2_MODE_DISABLE
//
// CANTX2 Source
#define ECAN_TX2_SOURCE_VAL ECAN_TX2_SOURCE_COMP
//
// CAN Capture Mode
#define ECAN_CAPTURE_MODE_VAL ECAN_CAPTURE_MODE_DISABLE
//
// CAN Clock Source
#define ECAN_CLOCK_SOURCE_MODE ECAN_CLOCK_MODE_PLL
//
// RXB0 Recieve Mode
#define ECAN_RXB0_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// RXB0 Double Buffer Mode
#define ECAN_RXB0_DBL_BUFFER_MODE_VAL ECAN_DBL_BUFFER_MODE_DISABLE
//
// RXB1 Recieve Mode
#define ECAN_RXB1_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B0 Tx/Rx mode Mode
#define ECAN_B0_TXRX_MODE_VAL ECAN_BUFFER_RX
//
// B0 Recieve Mode
#define ECAN_B0_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B0 Auto RTR Mode
#define ECAN_B0_AUTORTR_MODE ECAN_AUTORTR_MODE_DISABLE
//
// B1 Tx/Rx mode Mode
#define ECAN_B1_TXRX_MODE_VAL ECAN_BUFFER_RX
//
// B1 Recieve Mode
#define ECAN_B1_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B1 Auto RTR Mode
#define ECAN_B1_AUTORTR_MODE ECAN_AUTORTR_MODE_DISABLE
//
// B2 Tx/Rx mode Mode
#define ECAN_B2_TXRX_MODE_VAL ECAN_BUFFER_TX
//
// B2 Recieve Mode
#define ECAN_B2_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B2 Auto RTR Mode
#define ECAN_B2_AUTORTR_MODE ECAN_AUTORTR_MODE_DISABLE
//
// B3 Tx/Rx mode Mode
#define ECAN_B3_TXRX_MODE_VAL ECAN_BUFFER_TX
//
// B3 Recieve Mode
#define ECAN_B3_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B3 Auto RTR Mode
#define ECAN_B3_AUTORTR_MODE ECAN_AUTORTR_MODE_DISABLE
//
// B4 Tx/Rx mode Mode
#define ECAN_B4_TXRX_MODE_VAL ECAN_BUFFER_TX
//
// B4 Recieve Mode
#define ECAN_B4_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B4 Auto RTR Mode
#define ECAN_B4_AUTORTR_MODE ECAN_AUTORTR_MODE_DISABLE
//
// B5 Tx/Rx mode Mode
#define ECAN_B5_TXRX_MODE_VAL ECAN_BUFFER_TX
//
// B5 Recieve Mode
#define ECAN_B5_MODE_VAL ECAN_RECEIVE_ALL_VALID
//
// B5 Auto RTR Mode
#define ECAN_B5_AUTORTR_MODE ECAN_AUTORTR_MODE_DISABLE
//
// RXF0 Filter Enable/Disable
#define ECAN_RXF0_MODE_VAL ECAN_RXFn_ENABLE
//
// RXF0 Filter Type
#define ECAN_RXF0_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF0 Value
#define ECAN_RXF0_VAL 0x200L
//
// RXF0 Buffer Link
#define ECAN_RXF0_BUFFER_VAL RXB0
//
// RXF0 Mask Link
#define ECAN_RXF0_MASK_VAL ECAN_RXM0
//
// RXF1 Filter Enable/Disable
#define ECAN_RXF1_MODE_VAL ECAN_RXFn_ENABLE
//
// RXF1 Filter Type
#define ECAN_RXF1_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF1 Value
#define ECAN_RXF1_VAL 0x201L
//
// RXF1 Buffer Link
#define ECAN_RXF1_BUFFER_VAL RXB1
//
// RXF1 Mask Link
#define ECAN_RXF1_MASK_VAL ECAN_RXM0
//
// RXF2 Filter Enable/Disable
#define ECAN_RXF2_MODE_VAL ECAN_RXFn_ENABLE
//
// RXF2 Filter Type
#define ECAN_RXF2_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF2 Value
#define ECAN_RXF2_VAL 0x202L
//
// RXF2 Buffer Link
#define ECAN_RXF2_BUFFER_VAL B1
//
// RXF2 Mask Link
#define ECAN_RXF2_MASK_VAL ECAN_RXM0
//
// RXF3 Filter Enable/Disable
#define ECAN_RXF3_MODE_VAL ECAN_RXFn_ENABLE
//
// RXF3 Filter Type
#define ECAN_RXF3_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF3 Value
#define ECAN_RXF3_VAL 0x204L
//
// RXF3 Buffer Link
#define ECAN_RXF3_BUFFER_VAL RXB0
//
// RXF3 Mask Link
#define ECAN_RXF3_MASK_VAL ECAN_RXM0
//
// RXF4 Filter Enable/Disable
#define ECAN_RXF4_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF4 Filter Type
#define ECAN_RXF4_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF4 Value
#define ECAN_RXF4_VAL 0x0L
//
// RXF4 Buffer Link
#define ECAN_RXF4_BUFFER_VAL RXB0
//
// RXF4 Mask Link
#define ECAN_RXF4_MASK_VAL ECAN_RXM0
//
// RXF5 Filter Enable/Disable
#define ECAN_RXF5_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF5 Filter Type
#define ECAN_RXF5_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF5 Value
#define ECAN_RXF5_VAL 0x0L
//
// RXF5 Buffer Link
#define ECAN_RXF5_BUFFER_VAL RXB0
//
// RXF5 Mask Link
#define ECAN_RXF5_MASK_VAL ECAN_RXM0
//
// RXF6 Filter Enable/Disable
#define ECAN_RXF6_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF6 Filter Type
#define ECAN_RXF6_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF6 Value
#define ECAN_RXF6_VAL 0x0L
//
// RXF6 Buffer Link
#define ECAN_RXF6_BUFFER_VAL RXB0
//
// RXF6 Mask Link
#define ECAN_RXF6_MASK_VAL ECAN_RXM0
//
// RXF7 Filter Enable/Disable
#define ECAN_RXF7_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF7 Filter Type
#define ECAN_RXF7_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF7 Value
#define ECAN_RXF7_VAL 0x0L
//
// RXF7 Buffer Link
#define ECAN_RXF7_BUFFER_VAL RXB0
//
// RXF7 Mask Link
#define ECAN_RXF7_MASK_VAL ECAN_RXM0
//
// RXF8 Filter Enable/Disable
#define ECAN_RXF8_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF8 Filter Type
#define ECAN_RXF8_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF8 Value
#define ECAN_RXF8_VAL 0x0L
//
// RXF8 Buffer Link
#define ECAN_RXF8_BUFFER_VAL RXB0
//
// RXF8 Mask Link
#define ECAN_RXF8_MASK_VAL ECAN_RXM0
//
// RXF9 Filter Enable/Disable
#define ECAN_RXF9_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF9 Filter Type
#define ECAN_RXF9_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF9 Value
#define ECAN_RXF9_VAL 0x0L
//
// RXF9 Buffer Link
#define ECAN_RXF9_BUFFER_VAL RXB0
//
// RXF9 Mask Link
#define ECAN_RXF9_MASK_VAL ECAN_RXM0
//
// RXF10 Filter Enable/Disable
#define ECAN_RXF10_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF10 Filter Type
#define ECAN_RXF10_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF10 Value
#define ECAN_RXF10_VAL 0x0L
//
// RXF10 Buffer Link
#define ECAN_RXF10_BUFFER_VAL RXB0
//
// RXF10 Mask Link
#define ECAN_RXF10_MASK_VAL ECAN_RXM0
//
// RXF11 Filter Enable/Disable
#define ECAN_RXF11_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF11 Filter Type
#define ECAN_RXF11_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF11 Value
#define ECAN_RXF11_VAL 0x0L
//
// RXF11 Buffer Link
#define ECAN_RXF11_BUFFER_VAL RXB0
//
// RXF11 Mask Link
#define ECAN_RXF11_MASK_VAL ECAN_RXM0
//
// RXF12 Filter Enable/Disable
#define ECAN_RXF12_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF12 Filter Type
#define ECAN_RXF12_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF12 Value
#define ECAN_RXF12_VAL 0x0L
//
// RXF12 Buffer Link
#define ECAN_RXF12_BUFFER_VAL RXB0
//
// RXF12 Mask Link
#define ECAN_RXF12_MASK_VAL ECAN_RXM0
//
// RXF13 Filter Enable/Disable
#define ECAN_RXF13_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF13 Filter Type
#define ECAN_RXF13_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF13 Value
#define ECAN_RXF13_VAL 0x0L
//
// RXF13 Buffer Link
#define ECAN_RXF13_BUFFER_VAL RXB0
//
// RXF13 Mask Link
#define ECAN_RXF13_MASK_VAL ECAN_RXM0
//
// RXF14 Filter Enable/Disable
#define ECAN_RXF14_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF14 Filter Type
#define ECAN_RXF14_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF14 Value
#define ECAN_RXF14_VAL 0x0L
//
// RXF14 Buffer Link
#define ECAN_RXF14_BUFFER_VAL RXB0
//
// RXF14 Mask Link
#define ECAN_RXF14_MASK_VAL ECAN_RXM0
//
// RXF15 Filter Enable/Disable
#define ECAN_RXF15_MODE_VAL ECAN_RXFn_DISABLE
//
// RXF15 Filter Type
#define ECAN_RXF15_MSG_TYPE_VAL ECAN_MSG_STD
//
// RXF15 Value
#define ECAN_RXF15_VAL 0x0L
//
// RXF15 Buffer Link
#define ECAN_RXF15_BUFFER_VAL RXB0
//
// RXF15 Mask Link
#define ECAN_RXF15_MASK_VAL ECAN_RXM0
//
// RXM0 Type
#define ECAN_RXM0_MSG_TYPE ECAN_MSG_STD
//
// RXM0 Value
#define ECAN_RXM0_VAL 0xFFFL
//
// RXM1 Type
#define ECAN_RXM1_MSG_TYPE ECAN_MSG_STD
//
// RXM1 Value
#define ECAN_RXM1_VAL 0xFFFL
#endif
