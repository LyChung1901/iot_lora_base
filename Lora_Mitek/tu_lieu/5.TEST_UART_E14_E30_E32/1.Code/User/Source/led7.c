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

#include "led7.h"

#if (__LED7_H!=14032014)
    #error "Include Sai File led7.h"
#endif

static uint8_t Led7_Font[10]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};// Ma Anode chung
static uint8_t Led7_Index=0;
static uint8_t Led7_BufferData[NUMBER_LED7];
//static uint16_t Old_Value;

/*******************************************************************************
Noi Dung    :   Ghi du lieu hien thi len cac chan du lieu cua Led 7 thanh. 
Tham Bien   :   Data: du lieu hien thi. 
Tra Ve      :   Khong.
*******************************************************************************/

void LED7_DataOut(uint8_t Data)
{
    #ifdef LED7_DATA
        LED7_DATA=Data;
    #else
        LED7_DATA_A=(Data&0x01)?1:0;
        LED7_DATA_B=(Data&0x02)?1:0;
        LED7_DATA_C=(Data&0x04)?1:0;
        LED7_DATA_D=(Data&0x08)?1:0;
        LED7_DATA_E=(Data&0x10)?1:0;
        LED7_DATA_F=(Data&0x20)?1:0;
        LED7_DATA_G=(Data&0x40)?1:0;
        //LED7_DATA_DP=(Data&0x80)?1:0;
    #endif            
}

/*******************************************************************************
Noi Dung    :   Lay ma hien thi len LED7 cua gia tri so. 
Tham Bien   :   number    : Gia tri so hien thi. 
Tra Ve      :   Khong.
*******************************************************************************/

void LED7_CacuCode(uint16_t Number)
{
    int8_t i; 
    for(i=0;i<NUMBER_LED7;i++)
    {     
        Led7_BufferData[i]=Led7_Font[Number%10];
        Number=Number/10;
    }                     
#if (LED7_DISPLAY_ZERO==0)      // Khong hien thi so 0 o truoc cac chu so
    for(i=NUMBER_LED7-1;i>=1;i--)
    {  
        if(Led7_BufferData[i]!=Led7_Font[0]) break;
        Led7_BufferData[i]=0xff;
    }
#endif
}     

/*******************************************************************************
Noi Dung    :   Tat nguon cap cua tat ca cac LED7.
Tham Bien   :   Khong. 
Tra Ve      :   Khong.
*******************************************************************************/

void LED7_PowerOff(void)
{
   POWER_LED1=POWER_LED2=POWER_LED3=POWER_LED4=LED7_OFF;       
}

/*******************************************************************************
Noi Dung    :   Bat nguon cap cho 1 LED7. 
Tham Bien   :   Add: Vi tri con LED7 can bat nguon. 
Tra Ve      :   Khong.
*******************************************************************************/

void LED7_PowerOn(uint8_t Add)
{
    switch(Add)
    {
        case 0: POWER_LED1=LED7_ON,POWER_LED2=POWER_LED3=POWER_LED4=LED7_OFF;
        break;
        case 1: POWER_LED2=LED7_ON,POWER_LED1=POWER_LED3=POWER_LED4=LED7_OFF;
        break;
        case 2: POWER_LED3=LED7_ON,POWER_LED2=POWER_LED1=POWER_LED4=LED7_OFF;
        break;
        case 3: POWER_LED4=LED7_ON,POWER_LED2=POWER_LED3=POWER_LED1=LED7_OFF;
        break;    
    }
}

/*******************************************************************************
Noi Dung    :   Chuyen doi va hien thi gia tri so len LED7. 
Tham Bien   :   Value: Gia tri so hien thi. 
Tra Ve      :   Khong.
*******************************************************************************/

void LED7_Display(uint16_t Value)
{
    LED7_CacuCode(Value);
    LED7_PowerOff();
    LED7_DataOut(Led7_BufferData[Led7_Index]);
    LED7_PowerOn(Led7_Index); 
    Led7_Index++;
    if(Led7_Index>=NUMBER_LED7)Led7_Index=0;
} 

/*******************************************************************************
Noi Dung    :   Bat/Tat dau cham cua LED7 bat ky. 
Tham Bien   :   Add: Vi tri LED7 co dau cham can Bat/Tat.
                Status: 1 --> Bat.
                        0 --> Tat. 
Tra Ve      :   Khong.
*******************************************************************************/ 
   
void LED7_OnDot(uint8_t Add, uint8_t Status)
{
#ifdef NOTTEST_DOT
    if(Add==0)Led7_BufferData[0]|=0x80;  
    else
    {
        if(Status)Led7_BufferData[Add]&=0x7F;
        else Led7_BufferData[Add]|=0x80;
    }  
#else  
    if(Status)Led7_BufferData[Add]&=0x7F;
    else Led7_BufferData[Add]|=0x80;
#endif
}

/*******************************************************************************
Noi Dung    :   Tinh toan hien thi so thuc co dau phay dong. 
Tham Bien   :   Value: gia tri so thuc.
                *Index_dot: vi tri dau cham dong. 
Tra Ve      :   Co.
*******************************************************************************/ 

uint16_t LED7_PutFloat(float Value, uint8_t *Index_dot)
{
    uint8_t i,j; 
    uint16_t temp=1;
    uint16_t k=1;  
    
    uint16_t buff_value;  
    float buff_value1;
    uint16_t buff_value2; 
    
    buff_value = (uint16_t)(Value);   
    buff_value1 = Value - (float)buff_value;
    
    for(i=1;i<NUMBER_LED7+1;i++)  // Kiem tra xem co bao nhieu chu so phan nguyen
    {   
        temp*=10;
        if((buff_value/temp)==0)break;
    } 
    *Index_dot=NUMBER_LED7-i;
    for(j=0;j<(NUMBER_LED7-i);j++)
    {
        k*=10;
    }                                         
    buff_value2 = buff_value*k + (uint16_t)(buff_value1*k);
    return buff_value2;
}

/*------------------------------KET THUC FILE-------------------------------
 ______________________________MinhHa R&D Team______________________________*/
