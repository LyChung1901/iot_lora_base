/*****************************************************************************
  *Ten Tep          :     var.h
  *Ngay             :     14/03/2014
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham tinh toan, hien thi Led 7 thanh
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan dieu khien va chan du lieu 
                     cua LED7 vao file main.h   
    // Cac chan dieu khien
        #define POWER_LED4  PORTC_2
        #define POWER_LED3  PORTC_3
        #define POWER_LED2  PORTC_4
        #define POWER_LED1  PORTC_5
    // Chi dinh nghia 1 trong 2 kieu ket noi chan du lieu LED7
    // Ket noi cac chan du lieu vao cung 1 PORT cua VDK (A - LSB, DP - MSP)
        #define LED7_DATA   PORTD             
    // Ket noi cac chan du lieu vao cac chan khac nhau cua VDK
        #define LED7_DATA_A PORTB_0  
        #define LED7_DATA_B PORTB_1
        #define LED7_DATA_C PORTB_2
        #define LED7_DATA_D PORTC_0
        #define LED7_DATA_E PORTC_1
        #define LED7_DATA_F PORTC_2
        #define LED7_DATA_G PORTD_0
        #define LED7_DATA_DP PORTD_1
    // Co hien thi so 0
        LED7_DISPLAY_ZERO   1   // Hien thi so 0
        LED7_DISPLAY_ZERO   0   // Khong hien thi so 0                          
  ******************************************************************************
**/

#ifndef __LED7_H
#define __LED7_H    14032014

#include "main.h"

#ifndef NUMBER_LED7
    #define NUMBER_LED7         4   // Dinh nghia so Led hien thi   
#endif
#ifndef LED7_DISPLAY_ZERO
    #define LED7_DISPLAY_ZERO   0   // Hien thi so 0: 1 -> hien thi; 0 -> khong hien thi 
#endif 
#ifndef LED7_OFF   
    #define LED7_OFF    1
#endif
#ifndef LED7_ON 
    #define LED7_ON     0
#endif  
#define NOTTEST_DOT     1

/*******************************************************************************
Noi Dung    :   Ghi du lieu hien thi len cac chan du lieu cua Led 7 thanh. 
Tham Bien   :   Data: du lieu hien thi. 
Tra Ve      :   Khong.
*******************************************************************************/

void LED7_DataOut(uint8_t Data);

/*******************************************************************************
Noi Dung    :   Lay ma hien thi len LED7 cua gia tri so. 
Tham Bien   :   number    : Gia tri so hien thi. 
Tra Ve      :   Khong.
*******************************************************************************/
  
void LED7_CacuCode(uint16_t Number);

/*******************************************************************************
Noi Dung    :   Tat nguon cap cua tat ca cac LED7.
Tham Bien   :   Khong. 
Tra Ve      :   Khong.
*******************************************************************************/
  
void LED7_PowerOff(void);

/*******************************************************************************
Noi Dung    :   Bat nguon cap cho 1 LED7. 
Tham Bien   :   Add: Vi tri con LED7 can bat nguon. 
Tra Ve      :   Khong.
*******************************************************************************/
  
void LED7_PowerOn(uint8_t Add);

/*******************************************************************************
Noi Dung    :   Chuyen doi va hien thi gia tri so len LED7. 
Tham Bien   :   Value: Gia tri so hien thi. 
Tra Ve      :   Khong.
*******************************************************************************/
  
void LED7_Display(uint16_t Value);

/*******************************************************************************
Noi Dung    :   Bat/Tat dau cham cua LED7 bat ky. 
Tham Bien   :   Add: Vi tri LED7 co dau cham can Bat/Tat.
                Status: 1 --> Bat.
                        0 --> Tat. 
Tra Ve      :   Khong.
*******************************************************************************/
  
void LED7_OnDot(uint8_t Add, uint8_t Status);

/*******************************************************************************
Noi Dung    :   Tinh toan hien thi so thuc co dau phay dong. 
Tham Bien   :   Value: gia tri so thuc.
                *Index_dot: vi tri dau cham dong. 
Tra Ve      :   Co.
*******************************************************************************/
  
uint16_t LED7_PutFloat(float Value, uint8_t *Index_dot);

#endif 
/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/







