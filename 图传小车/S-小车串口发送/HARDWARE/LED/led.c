#include "led.h"

/******************************************************************
*函数名称:	LED_Init
*函数功能:	初始化LED
*函数参数:	无
*返 回 值:	无
*******************************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//使能端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;	//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//50M
	GPIO_Init(GPIOB, &GPIO_InitStructure);					//根据设定参数初始化GPIO
	
	LED0 = 1;
	LED1 = 1;
}


/*蓝牙端口初始化*/
void BluetoothIO_init()
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//使能端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;			//端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		//下拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M
	GPIO_Init(GPIOB, &GPIO_InitStructure);				//根据设定参数初始化GPIO
}


