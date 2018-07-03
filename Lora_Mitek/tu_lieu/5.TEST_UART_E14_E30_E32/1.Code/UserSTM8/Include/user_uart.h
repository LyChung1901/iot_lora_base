/*****************************************************************************
  *Ten Tep          :     user_uart.h
  *Ngay             :     27/07/2016
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac ham cau hinh UART1 trong STM8F003
  ******************************************************************************/

#ifndef __USER_UART1_H
#define __USER_UART1_H    27012016

#include "main.h"

/*******************************************************************************
Noi Dung    :   Cau hinh UART1.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void UART1_Configuration(uint32_t BaudRate);

/*******************************************************************************
Noi Dung    :   Truyen 1 ky tu.
Tham Bien   :   Char: Ky tu can truyen.
Tra Ve      :   Khong.
*******************************************************************************/

void UART1_PutChar(char Char);

/*******************************************************************************
Noi Dung    :   Truyen 1 chuoi ky tu.
Tham Bien   :   Str: Chuoi ky tu can truyen.
Tra Ve      :   Khong.
*******************************************************************************/

void UART1_PutString(char* Str);

#endif
/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Temp______________________________*/
