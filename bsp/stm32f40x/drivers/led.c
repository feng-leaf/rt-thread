/**
 ****************************************************************************************************
 * @file        led.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2021-10-14
 * @brief       LED 驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 探索者 F407开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20211014
 * 第一次发布
 *
 ****************************************************************************************************
 */
 
#include "led.h"


/**
 * @brief       初始化LED相关IO口, 并使能时钟
 * @param       无
 * @retval      无
 */
void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);	 //使能PF端口时钟
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PF.11 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 		     //推挽输出
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOF, &GPIO_InitStructure);					 //根据设定参数初始化
    GPIO_SetBits(GPIOF,GPIO_Pin_9);						 //PF.11 输出高

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	    		 //LED1-->PF.12 端口配置, 推挽输出
    GPIO_Init(GPIOF, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
    GPIO_SetBits(GPIOF,GPIO_Pin_10); 						 //PF.12 输出高 
}
