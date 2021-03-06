#include "timer.h"
#include "nrf24l01.h"


u16 T0_Arr;	//T0自动重装值

/**********************************************************
函数功能：定时器0中断初始化
入口参数：arr：定时时间，单位us
返回参数：无
***********************************************************/
void TIM0Int_Init(u16 arr)
{ 
	T0_Arr = 65535-arr;			//计算重装值 
	TMOD &= 0xF0;				//设置定时器模式
	TMOD |= 0x01; 				//选择工作方式1
	TH0 = T0_Arr/256;			//设置初始值
	TL0 = T0_Arr%256; 
	EA = 1;			 			//打开总中断
	ET0 = 1;		 			//打开定时器中断
	TR0 = 1;		 			//启动定时器	
}


extern u8 TXbuf[3];
extern u8 LOCK;

/**********************************************************
函数功能：定时器1中断服务函数
入口参数：无
返回参数：无
***********************************************************/
void TIM0_Int() interrupt 1
{
	static u8 T0count=0;
		
	TH0 = T0_Arr/256;		//设置重装值
	TL0 = T0_Arr%256; 
					
	TXbuf[0]=LOCK;
	Nrf24l01TXPacket(TXbuf);	//无线发送数据
			
	T0count++;
	if(T0count>99) T0count = 0;	

	if((T0count%20)==0)		//运行指示
	{	
		LED0 = !LED0;
	}
}


