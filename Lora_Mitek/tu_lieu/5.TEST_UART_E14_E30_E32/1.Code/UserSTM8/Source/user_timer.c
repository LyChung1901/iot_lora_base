/*****************************************************************************
  *Ten Tep          :     user_timer.c
  *Ngay             :     20/04/2015
  *Tac Gia          :     MinhHa R&D Team
  *Cong Ty          :     MinhHaGroup
  *Webside          :     mcu.banlinhkien.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham cau hinh TIM trong STM8
  ******************************************************************************/

#include "user_timer.h"
#if (__USER_TIMER_H!=20042015)  
    #error "Include Sai #File user_timer.h"
#endif

/*******************************************************************************
Noi Dung    :   Cau hinh TIM1.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void TIM1_Configuration(void)
{
    TIM1_DeInit();                                                                  
    TIM1_TimeBaseInit(16,TIM1_COUNTERMODE_UP,999,0);//repeat =0
    TIM1_SelectOCxM(TIM1_CHANNEL_1 ,TIM1_OCMODE_PWM1);
    TIM1_OC1PolarityConfig(TIM1_OCPOLARITY_LOW );
    TIM1_SetCompare1(0);
    TIM1_OC1PreloadConfig(ENABLE);
    TIM1_CCxCmd(TIM1_CHANNEL_1, ENABLE);
    TIM1_CtrlPWMOutputs(ENABLE);
     //TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);    // Kich hoat ngat tran TIM1 khi co update
    TIM1_Cmd(ENABLE);
}

/*******************************************************************************
Noi Dung    :   Cau hinh TIM2.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void TIM2_Configuration(void)
{
	TIM2_DeInit();
    TIM2_TimeBaseInit(TIM2_PRESCALER_256,62500);    // 1s  
    TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);     
    TIM2_Cmd(DISABLE);			      
}

void TIM2_Disable(void)
{
    TIM2_Cmd(DISABLE);    
    TIM2->CNTRH =0;
    TIM2->CNTRL =0;    
}

void TIM2_Enable(void)
{
    TIM2_Cmd(ENABLE);
}

/*******************************************************************************
Noi Dung    :   Cau hinh TIM4.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void TIM4_Configuration(void)
{
    TIM4_DeInit();
    TIM4_TimeBaseInit(TIM4_PRESCALER_128 ,124); // cai dat bo chia va Period
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);     // Kich hoat ngat tran TIM4 khi co update
    TIM4_Cmd(ENABLE);	
}

/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Temp______________________________*/