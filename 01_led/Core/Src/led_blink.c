/*
 * led_blink.c
 *
 *  Created on: May 29, 2024
 *      Author: boobathi
 */

#include "stm32f4xx.h"
void delayMs(int n);
void led_blink()
{
	RCC->AHB1ENR |= 1; /* enable GPIOA clock */
	GPIOA->MODER |= (0<<11);
	GPIOA->MODER |= (1<<10); /* set pin to output mode */
	while(1)
	{
			GPIOA->ODR |= 0x00000020; /* turn on LED */
			delayMs(500);
			GPIOA->ODR &= ~0x00000020; /* turn off LED */
			delayMs(500);
	}
}
void delayMs(int n)
{
	int i;
	for (; n > 0; n--)
	for (i = 0; i < 3195; i++) ;
}
