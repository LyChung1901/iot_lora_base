/*****************************************************************************
  *Ten Tep          :     var.h
  *Ngay             :     20/06/2016
  *Tac Gia          :     CLB Dien Tu Minh Ha
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac bien toan cuc su dung trong Project
  ******************************************************************************/

#ifndef __VAR_H
#define __VAR_H
unsigned int  t,DUTY=0;
//__no_init uint8_t Value @0x4000;    // Khai bao bien EEPROM    
//__eeprom uint8_t i=100;
uint16_t AdcValue=0,NHAN1=0,NHAN2=0;
uint16_t ADC=0,ADC_cur=0,S=0,N=0;
uint8_t VALUE_ADC[50];
uint8_t VALUE_NHAN[50];
uint8_t IN_LED7[50];
char BufferUart[30];
uint16_t IndexByteInBuffer=0;
uint16_t NumberByteInBuffer=0;
uint16_t FlagGetData;
uint16_t IN_LED=0;
uint16_t DEM=0,i=0,j0=0,j1=0,j2=0,j3=0;
#endif  

/*------------------------------ KET THUC FILE -------------------------------
 ______________________________CLB Dien Tu Minh Ha____________________________*/ 