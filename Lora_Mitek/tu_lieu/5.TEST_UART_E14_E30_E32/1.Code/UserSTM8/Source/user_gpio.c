/*****************************************************************************
  *Ten Tep          :     user_gpio.c
  *Ngay             :     20/04/2015
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham cau hinh GPIO trong STM8
  ******************************************************************************/

#include "user_gpio.h"
#if (__USER_GPIO_H!=20042015)  
    #error "Include Sai #File user_gpio.h"
#endif

/*******************************************************************************
Noi Dung    :   Cau hinh GPIO.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void GPIO_Configuration(void)
{
/********************************* PORTA *************************************/
    DDRA=0xFF; 
    CRA1=0xFF;
    CRA2=0xFF;
    PORTA=0xFF;
/********************************* PORTB *************************************/
/********************************* PORTC *************************************/
    DDRC=0x07;
    CRC1=0xFF;
    CRC2=0x00;
    PORTC=0x00;
/********************************* PORTD *************************************/
    DDRD=0xBF;
    CRD1=0xBF;
    CRD2=0xBF;
    PORTD=0xFF;
/********************************* PORTE *************************************/

/********************************* PORTF *************************************/

/********************************* PORTG *************************************/

}

/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Temp______________________________*/