/*****************************************************************************
  *Ten Tep          :     user_uart.c
  *Ngay             :     27/01/2016
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham cau hinh UART1 trong STM8F003
  ******************************************************************************/

#include "user_uart.h"
#if (__USER_UART1_H!=27012016)  
    #error "Include Sai #File user_uart1.h"
#endif
extern char BufferUart[30];
extern uint16_t IndexByteInBuffer;
extern uint16_t NumberByteInBuffer;
extern uint16_t FlagGetData;
extern uint16_t S,N;

#pragma vector = UART1_R_RXNE_vector
__interrupt void NgatNhanUART1(void)
{  
    if(UART1_GetFlagStatus(UART1_FLAG_RXNE)!=RESET)
    {
       UART1_ClearFlag(UART1_FLAG_RXNE);  
     BufferUart[IndexByteInBuffer++] = (uint8_t)(UART1->DR);
     }
    
    if(UART1_GetFlagStatus(UART1_FLAG_IDLE)!=RESET)
    {
       UART1->SR;
       UART1->DR;
        NumberByteInBuffer = IndexByteInBuffer;
     //   IndexByteInBuffer=0; 
        FlagGetData = 1;
    //  UART2_PutString("NGAT_IDLE\n");
    }  
}

/*******************************************************************************
Noi Dung    :   Cau hinh UART1.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void UART1_Configuration(uint32_t BaudRate)
{
    UART1_DeInit();
    UART1_Init(BaudRate,  UART1_WORDLENGTH_8D, 
                      UART1_STOPBITS_1, 
                      UART1_PARITY_NO, 
                      UART1_SYNCMODE_CLOCK_DISABLE, 
                      UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE,ENABLE);
    UART1_ITConfig(UART1_IT_IDLE,ENABLE);
    UART1_Cmd(ENABLE);
}

/*******************************************************************************
Noi Dung    :   Truyen 1 ky tu.
Tham Bien   :   Char: Ky tu can truyen.
Tra Ve      :   Khong.
*******************************************************************************/

void UART1_PutChar(char Char)
{
    UART1_SendData8(Char);
    while(UART1_GetFlagStatus(UART1_FLAG_TC)==RESET);
}

/*******************************************************************************
Noi Dung    :   Truyen 1 chuoi ky tu.
Tham Bien   :   Str: Chuoi ky tu can truyen.
Tra Ve      :   Khong.
*******************************************************************************/

void UART1_PutString(char* Str)
{
    while(*Str)
    {
       UART1_PutChar(*Str);
       Str++;
    }
}


/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Temp______________________________*/
