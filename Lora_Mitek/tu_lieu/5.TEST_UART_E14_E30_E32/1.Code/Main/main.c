/*****************************************************************************
  *Ten Tep          :     main.c
  *Ngay             :     29/06/2015
  *Tac Gia          :     CLB Dien Tu Minh Ha
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     STM8S105K4T6 Project Example
  ******************************************************************************/

#include "main.h"  
#include "var.h"

#if (__MAIN_H!=29062016)
    #error "Include Sai File main.h"
#endif

char a[10] ;
char LED1[10] = "LED1";
char LED2[10] = "LED2";
char LED3[10] = "LED3";
char LED4[10] = "LED4";

uint8_t x1,x2,x3,x4;

void main(void)
{
	// Khai bao cac bien su dung trong ham main.c
  

	
/********************************* SYSTEM ************************************/
    CLK_HSICmd(ENABLE); //cho phep dung nguon clock toc do cao 16Mhz
    CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);  // 	chia 1 				
/*_________________________________ GPIO ____________________________________*/
    GPIO_Configuration();
    //EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC,EXTI_SENSITIVITY_FALL_ONLY);

/*_________________________________ EXTINT __________________________________*/
    //EXTINT_Configuration();
    
/********************************* TIMER *************************************/
/*________________________________ TIMER1 ___________________________________*/
    //TIM1_Configuration();
    

/*________________________________ TIMER2 ___________________________________*/
    //TIM2_Configuration();

/*________________________________ TIMER4 ___________________________________*/
//    TIM4_Configuration();	

/********************************** ADC1 *************************************/   
    //ADC1_Configuration();	
	
/********************************** USART ************************************/   
/*_________________________________ UART1 ___________________________________*/
   UART1_Configuration(9600);

/*_________________________________ UART2 ___________________________________*/
   // UART1_Configuration(9600);	
    delay_ms(200);
	
/********************************** IWDG *************************************/   
    //IWDG_Configuration();
 
/********************************* EEPROM ************************************/   
    //EEPROM_Configuration();   
enableInterrupts();

UART1_PutString("HELLO_SANG\n");

LED_1 = 1;
LED_2 = 1;
LED_3 = 1;
LED_4 = 1;
M0 = M1 = 0;

 while(1)
   { 
     
    if((FlagGetData == 1)&&(AUX))
    {     
          FlagGetData = 0;
          UART1_PutString("OK_MAIN\n");
          BufferUart[IndexByteInBuffer] = NULL;
          strcpy(a,BufferUart);  
          IndexByteInBuffer = 0;
          NumberByteInBuffer=0;
                                                                                              
              x1 = strcmp(a,LED1);
              x2 = strcmp(a,LED2);
              x3 = strcmp(a,LED3);
              x4 = strcmp(a,LED4);
              
              if(x1 == 0)
                {
                  LED_1 = ~ LED_1;
                  delay_ms(100);
                }
              else if(x2 == 0)
                {
                  LED_2 = ~ LED_2;
                  delay_ms(100);
                }
              else if(x3 == 0)
                {
                  LED_3 = ~ LED_3;
                  delay_ms(100);
                }
              else if(x4 == 0)
                {
                  LED_4 = ~ LED_4;
                  delay_ms(100);
                }
              else UART1_PutString(a);

     }
    // kiem tra nut nhan va gui ky tu di
    if(BUT_1 == 0)
      {
        delay_ms(10);
        if(BUT_1 == 0)
          {
            while(BUT_1 == 0);
            UART1_PutString(LED1);
            delay_ms(300);
          }
       }
    if(BUT_2 == 0)
      {
        delay_ms(10);
        if(BUT_2 == 0)
          {
            while(BUT_2 == 0);
            UART1_PutString(LED2);
            delay_ms(300);
          }
       }
    if(BUT_3 == 0)
      {
        delay_ms(10);
        if(BUT_3 == 0)
          {
            while(BUT_3 == 0);
            UART1_PutString(LED3);
            delay_ms(300);
          }
       }
     if(BUT_4 == 0)
      {
        delay_ms(10);
        if(BUT_4 == 0)
          {
            while(BUT_4 == 0);
            UART1_PutString(LED4);
            delay_ms(300);
          }
        
      }
   }     
}    

/*------------------------------ KET THUC FILE -------------------------------
 ______________________________CLB Dien Tu Minh Ha____________________________*/ 