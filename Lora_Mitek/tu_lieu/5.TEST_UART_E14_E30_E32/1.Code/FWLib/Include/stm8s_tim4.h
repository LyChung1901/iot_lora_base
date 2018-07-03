/**
  ******************************************************************************
  * @file stm8s_tim4.h
  * @brief This file contains all functions prototype and macros for the TIM4 peripheral.
  * @author STMicroelectronics - MCD Application Team
  * @version V1.1.1
  * @date 06/05/2009
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  * @image html logo.bmp
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_TIM4_H
#define __STM8S_TIM4_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Exported types ------------------------------------------------------------*/

/** @addtogroup TIM4_Exported_Types
  * @{
  */



/** TIM4 Prescaler */
typedef enum
{
  TIM4_PRESCALER_1  = ((u8)0x00),
  TIM4_PRESCALER_2    = ((u8)0x01),
  TIM4_PRESCALER_4    = ((u8)0x02),
  TIM4_PRESCALER_8     = ((u8)0x03),
  TIM4_PRESCALER_16   = ((u8)0x04),
  TIM4_PRESCALER_32     = ((u8)0x05),
  TIM4_PRESCALER_64    = ((u8)0x06),
  TIM4_PRESCALER_128   = ((u8)0x07)
} TIM4_Prescaler_TypeDef;

#define IS_TIM4_PRESCALER_OK(PRESCALER) (((PRESCALER) == TIM4_PRESCALER_1  ) || \
    ((PRESCALER) == TIM4_PRESCALER_2    ) || \
    ((PRESCALER) == TIM4_PRESCALER_4    ) || \
    ((PRESCALER) == TIM4_PRESCALER_8  ) || \
    ((PRESCALER) == TIM4_PRESCALER_16   ) || \
    ((PRESCALER) == TIM4_PRESCALER_32     ) || \
    ((PRESCALER) == TIM4_PRESCALER_64    ) || \
    ((PRESCALER) == TIM4_PRESCALER_128   ) )

/** TIM4 One Pulse Mode */
typedef enum
{
  TIM4_OPMODE_SINGLE                 = ((u8)0x01),
  TIM4_OPMODE_REPETITIVE             = ((u8)0x00)
} TIM4_OPMode_TypeDef;

#define IS_TIM4_OPM_MODE_OK(MODE) (((MODE) == TIM4_OPMODE_SINGLE) || \
                                   ((MODE) == TIM4_OPMODE_REPETITIVE))

/** TIM4 Prescaler Reload Mode */
typedef enum
{
  TIM4_PSCRELOADMODE_UPDATE          = ((u8)0x00),
  TIM4_PSCRELOADMODE_IMMEDIATE       = ((u8)0x01)
} TIM4_PSCReloadMode_TypeDef;

#define IS_TIM4_PRESCALER_RELOAD_OK(RELOAD) (((RELOAD) == TIM4_PSCRELOADMODE_UPDATE) || \
    ((RELOAD) == TIM4_PSCRELOADMODE_IMMEDIATE))

/** TIM4 Update Source */
typedef enum
{
  TIM4_UPDATESOURCE_GLOBAL           = ((u8)0x00),
  TIM4_UPDATESOURCE_REGULAR          = ((u8)0x01)
} TIM4_UpdateSource_TypeDef;

#define IS_TIM4_UPDATE_SOURCE_OK(SOURCE) (((SOURCE) == TIM4_UPDATESOURCE_GLOBAL) || \
    ((SOURCE) == TIM4_UPDATESOURCE_REGULAR))

/** TIM4 Event Source */
typedef enum
{
  TIM4_EVENTSOURCE_UPDATE            = ((u8)0x01)
}TIM4_EventSource_TypeDef;

#define IS_TIM4_EVENT_SOURCE_OK(SOURCE) ((SOURCE == 0x01))

/** TIM4 Flags */
typedef enum
{
  TIM4_FLAG_UPDATE                   = ((u8)0x01)
}TIM4_FLAG_TypeDef;

#define IS_TIM4_GET_FLAG_OK(FLAG) ((FLAG) == TIM4_FLAG_UPDATE)



/** TIM4 interrupt sources */
typedef enum
{
  TIM4_IT_UPDATE                     = ((u8)0x01)
}TIM4_IT_TypeDef;

#define IS_TIM4_IT_OK(IT) ((IT) == TIM4_IT_UPDATE)



/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @addtogroup TIM4_Exported_Functions
  * @{
  */
void TIM4_DeInit(void);// KHOI TAO GIA TRI BAN DAU CHO TIM4
void TIM4_TimeBaseInit(TIM4_Prescaler_TypeDef TIM4_Prescaler, u8 TIM4_Period);// KHOI TAO HAM DINH THOI CO BAN
void TIM4_Cmd(FunctionalState NewState);
void TIM4_ITConfig(TIM4_IT_TypeDef TIM4_IT, FunctionalState NewState);//CAU HINH NGAT
void TIM4_UpdateDisableConfig(FunctionalState Newstate);
void TIM4_UpdateRequestConfig(TIM4_UpdateSource_TypeDef TIM4_UpdateSource);
void TIM4_SelectOnePulseMode(TIM4_OPMode_TypeDef TIM4_OPMode);
void TIM4_PrescalerConfig(TIM4_Prescaler_TypeDef Prescaler, TIM4_PSCReloadMode_TypeDef TIM4_PSCReloadMode);
void TIM4_ARRPreloadConfig(FunctionalState Newstate);
void TIM4_GenerateEvent(TIM4_EventSource_TypeDef TIM4_EventSource);
void TIM4_SetCounter(u8 Counter);
void TIM4_SetAutoreload(u8 Autoreload);
u8 TIM4_GetCounter(void);
TIM4_Prescaler_TypeDef TIM4_GetPrescaler(void);
FlagStatus TIM4_GetFlagStatus(TIM4_FLAG_TypeDef TIM4_FLAG);
void TIM4_ClearFlag(TIM4_FLAG_TypeDef TIM4_FLAG);
ITStatus TIM4_GetITStatus(TIM4_IT_TypeDef TIM4_IT);
void TIM4_ClearITPendingBit(TIM4_IT_TypeDef TIM4_IT);


/**
  * @}
  */

#endif /* __STM8S_TIM4_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
