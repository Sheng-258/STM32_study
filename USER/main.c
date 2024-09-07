#include "stm32f10x.h"
#include "stdint.h"
uint16_t temp,i;
 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
 int main(void)
 {	
  GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	    //Enable GPIOB Clock
  GPIO_InitStructure.GPIO_Pin = 0x03ff;			    //LED1-->PB.8, PB8 Configuration,LED2-->PB.9,LED3-->PB.10,LED4-->PB.11
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //Configure PB8 as a push-pull output
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO frequency 50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     //init pb8-11
  //GPIO_SetBits(GPIOB,GPIO_Pin_8);					//PB.8 high
  //use GPIO_Write(GPIOB,0xoFFFE); all I/O write shuju;
  while(1)
	{ 
		temp = 0xfffe;
		for(i=0;i<10;i++)
		{ 	
			GPIO_Write(GPIOB,temp);
			Delay(6000);
			temp=temp<<1;
		}
		Delay(5000);
		temp = 0xfe00;
		for(i=0;i<10;i++)
		{	 GPIO_Write(GPIOB,temp);
			 Delay(6000);
			 temp=(temp>>1)+0x8000;
			
		}
		Delay(5000);
		/*GPIO_Write(GPIOB,0x0feff);
		Delay(2000);
		GPIO_Write(GPIOB,0x0fdff);
		Delay(2000);
		GPIO_Write(GPIOB,0x0fbff);
		Delay(2000);
		GPIO_Write(GPIOB,0x0f7ff);
		Delay(2000);*/
		/*GPIO_SetBits(GPIOB,GPIO_Pin_8);
		Delay(2000);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		Delay(2000);
		GPIO_SetBits(GPIOB,GPIO_Pin_8);
		GPIO_SetBits(GPIOB,GPIO_Pin_9);
		Delay(2000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_9);
		Delay(2000);
		GPIO_SetBits(GPIOB,GPIO_Pin_9);
		GPIO_SetBits(GPIOB,GPIO_Pin_10);
		Delay(2000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_10);
		Delay(2000);
		GPIO_SetBits(GPIOB,GPIO_Pin_10);
		GPIO_SetBits(GPIOB,GPIO_Pin_11);
		Delay(2000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_11);
		Delay(2000);
		GPIO_SetBits(GPIOB,GPIO_Pin_11);*/
		/*GPIO_WriteBit(GPIOB,GPIO_Pin_8,0);
		Delay(2000);
		GPIO_WriteBit(GPIOB,GPIO_Pin_8,1);
		GPIO_WriteBit(GPIOB,GPIO_Pin_9,0);
		Delay(2000);
		GPIO_WriteBit(GPIOB,GPIO_Pin_9,1);
		GPIO_WriteBit(GPIOB,GPIO_Pin_10,0);
		Delay(2000);

		GPIO_WriteBit(GPIOB,GPIO_Pin_10,1);
		GPIO_WriteBit(GPIOB,GPIO_Pin_11,0);
		Delay(2000);
		GPIO_WriteBit(GPIOB,GPIO_Pin_11,1);*/
		//GPIO_SetBits(GPIOB,GPIO_Pin_11|GPIO_Pin_10);//cao zuo liang ge I/O, use GPIO_Pin_11,jiushi jiang zhe ge I/O zhi 1,qi yu zhi 0; #define GPIO_Pin_11 ((uint16_t)0x0800)
	}
 }



