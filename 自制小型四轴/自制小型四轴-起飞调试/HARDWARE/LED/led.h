#ifndef LED_H_
#define LED_H_

#include "sys.h"

#define LED0 PBout(10)	//PB10
#define LED1 PBout(1)	//PB1


/******************************************************************
*函数名称:	LED_Init
*函数功能:	初始化LED
*函数参数:	无
*返 回 值:	无
*******************************************************************/
void LED_Init(void);

#endif
