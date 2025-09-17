#include <stm32f10x.h>
#include "Delays.h"

void Delay_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
}

/**
  * @brief  Delays miliseconds. DO NOT USE IN ISRs!
  * @param  miliseconds - a numer of miliseconds to delay. MAX=59600
  * @retval none
  */
void Delay_ms(u32 miliseconds)
{
	u32 quot, reminder, i;
	
	quot = ((SystemCoreClock/1000)*miliseconds) / 0x01000000;	//modulo 24-bit counter
	reminder = ((SystemCoreClock/1000)*miliseconds) % 0x01000000;;
	
	SysTick_Config(reminder);
	while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)==0);	//czekaj na COUNT FLAG = 1;

	if (quot)
	{
		SysTick->LOAD  = 0xffffff;                                  /* set reload register */
		for (i=0;i<quot;i++)
		{
			while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)==0);	//czekaj na COUNT FLAG = 1;			
		}
		
	}
	SysTick->CTRL = DISABLE;
}

/**
  * @brief  Delays us microseconds, DO NOT USE IN ISRs!
  * @param  us - a numer of microseconds to delay, limited to 233000 us.
  * @retval none
  */
void Delay_us(u32 us)
{

	if (us > 233000 ) us = 233000;	//233016 = 2^24 / (72MHz/10^6)
	SysTick_Config((SystemCoreClock/1000000)*us);
	while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)==0);	//czekaj na COUNT FLAG = 1;
	SysTick->CTRL = DISABLE;	//bit0:ENABLE=1; bit2:CLKSOURCE = HCLK;
}

/**
  * @brief  Delay using a loop, CAN BE USED IN ISRs!
  *         A single loop cycle takes 9 cycles of fclk
  *         that is, at fclk=72MHz a single loop cyclke will take 125ns,
  *         for 1ms => delay=8'000.
  * @param  delay - a delay (full 32bit).
  * @retval none
  */
void Delay_L(uint32_t delay)
{
	uint32_t i=delay;
	while(i--);
}
