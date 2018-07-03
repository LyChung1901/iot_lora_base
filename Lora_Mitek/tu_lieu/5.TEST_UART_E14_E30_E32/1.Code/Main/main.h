/*******************************************************************************
  *Ten Tep         :     main.h
  *Ngay            :     29/06/2016
  *Tac Gia         :     CLB Dien Tu Minh Ha
  *Cong Ty         :     MinhHaGroup
  *Webside         :     mcu.banlinhkien.vn
  *Phien Ban       :     V1.0
  *Tom Tat         :     Khai bao cac thu vien.
  *                      Cau hinh mot so chuc nang cho trinh bien dich.
  *                      Cau hinh mot so chuc nang cho CHIP.
  *                      Dinh nghia I/O.
  *
  *
  *****************************************************************************/

#ifndef __MAIN_H
#define __MAIN_H    29062016    

#define FLASH_ADDR _Pragma("location=\"FLASH\"")
	  
/*    Kieu So Nguyen Co Dau    */
typedef long  int        int32_t;
typedef int              int16_t;
typedef char             int8_t;

/*	Kieu So Nguyen Khong Dau */
typedef unsigned long    uint32_t;
typedef unsigned int     uint16_t;
typedef unsigned char    uint8_t;
/*	Kieu So Thuc */
typedef float            float32_t;

/******************************************************************************
COMPILER LIB - COMPILER LIB - COMPILER LIB - COMPILER LIB - COMPILER LIB
******************************************************************************/
#include "stdio.h"
#include "string.h"

/******************************************************************************
FWLib - FWLib - FWLib - FWLib - FWLib - FWLib - FWLib - FWLib - FWLib - FWLib 
******************************************************************************/
#include "defstm8s.h"
#include "stm8s_clk.h"
#include "stm8s_exti.h"
#include "stm8s_adc1.h"
#include "stm8s_tim1.h"
#include "stm8s_tim2.h"
#include "stm8s_tim4.h"
#include "stm8s_uart1.h"
#include "stm8s_iwdg.h"
#include "stm8s_flash.h"

/******************************************************************************
USERSTM8 - USERSTM8 - USERSTM8 - USERSTM8 - USERSTM8 - USERSTM8 - USERSTM8 
******************************************************************************/
#include "user_delay.h"
#include "user_gpio.h"
//#include "user_extint.h"
#include "user_adc.h"
#include "user_timer.h"
#include "user_uart.h"
//#include "user_eeprom.h"
//#include "user_iwdg.h"

/******************************************************************************
USER - USER - USER - USER - USER - USER - USER - USER - USER - USER - USER 
******************************************************************************/
//#include "led7.h" 
/******************************************************************************
DEFINE GPIO - DEFINE GPIO - DEFINE GPIO - DEFINE GPIO - DEFINE GPIO - DEFINE GPIO
******************************************************************************/
//______________________I/O A ____________________________
#define  LED_1       PORTA_1
#define  LED_2       PORTA_2
#define  LED_3       PORTA_3
#define  LED_4       PORTD_4
#define  M0          PORTD_2
#define  M1          PORTD_3
//______________________I/O B ____________________________

//______________________I/O C ____________________________

#define  BUT_1       PINC_3
#define  BUT_2       PINC_4
#define  BUT_3       PINC_5
#define  BUT_4       PINC_6
#define  AUX         PINC_7

//______________________I/O D ____________________________

//______________________I/O E ____________________________

//______________________I/O F ____________________________

//______________________I/O G ____________________________

//______________________I/O H ____________________________

//______________________I/O I ____________________________

#endif

/*------------------------------ KET THUC FILE -------------------------------
 ______________________________CLB Dien Tu Minh Ha____________________________*/ 