/****************************************************************************
 *   $Id:: timer.c 5823 2010-12-07 19:01:00Z usb00423                       $
 *   Project: NXP LPC17xx Timer for PWM example
 *
 *   Description:
 *     This file contains timer code example which include timer 
 *     initialization, timer interrupt handler, and APIs for timer access.
 *
 *****************************************************************************/

#include "lpc17xx.h"
#include "type.h"
#include "timer.h"


#define BITSET(x) |= (1 << x) // macros for clearing and setting bits
#define BITCLEAR(x) &= ~(1<<x)

volatile uint32_t timer0_m0_counter = 0;

/******************************************************************************
** Function name:		Timer0_IRQHandler
******************************************************************************/
void TIMER0_IRQHandler (void) 
{  
  
	
	
	
	
  return;
}

/******************************************************************************
** Function name:		enable_timer
** parameters:			timer number: 0 or 1 or 2 or 3
** Returned value:		None
******************************************************************************/
void enable_timer( uint8_t timer_num )
{
  switch(timer_num){
		case 0:		LPC_TIM0->TCR BITSET(0);
							break;
		
		case 1: 	LPC_TIM1->TCR BITSET(0);
							break;
		
		case 2: 	LPC_TIM2->TCR BITSET(0);
							break;
		
		case 3: 	LPC_TIM3->TCR BITSET(0);
							break;
		
		default:	break;

	}

  return;
}

/******************************************************************************
** Function name:		disable_timer
** parameters:			timer number: 0 or 1 oe 2 or 3
** Returned value:		None
******************************************************************************/
void disable_timer( uint8_t timer_num )
{
    switch(timer_num){
		case 0:		LPC_TIM0->TCR BITCLEAR(0);
							break;
		
		case 1: 	LPC_TIM1->TCR BITCLEAR(0);
							break;
		
		case 2: 	LPC_TIM2->TCR BITCLEAR(0);
							break;
		
		case 3: 	LPC_TIM3->TCR BITCLEAR(0);
							break;
		
		default:	break;

	}
	
  return;
}

/******************************************************************************
** Function name:		reset_timer
** parameters:			timer number: 0 or 1 or 2 or 3
** Returned value:		None
******************************************************************************/
void reset_timer( uint8_t timer_num )
{
  switch(timer_num){
		case 0:		LPC_TIM0->TCR BITSET(1);
							break;
		
		case 1: 	LPC_TIM1->TCR BITSET(1);
							break;
		
		case 2: 	LPC_TIM2->TCR BITSET(1);
							break;
		
		case 3: 	LPC_TIM3->TCR BITSET(1);
							break;
		
		default:	break;

	}

  return;
}

/******************************************************************************
** Function name:		init_timer_0
**
** Descriptions:		Initialize timer, set timer interval, reset timer,
**						      install timer interrupt handler
**
** Returned value:		true or false, if the interrupt handler can't be
**						installed, return false.
** 
******************************************************************************/
uint32_t init_timer0 ( void)
{
  uint32_t pclk;

	timer0_m0_counter = 0;
		
/*
  -- Enable Power Control Bit for Timer
	-- Select Timer Pins through PinSelect Register for Port 1.28  MAT0.0
	-- Clear MATx interrupt
	-- Set Peripheral Clock (By default, the PCLKSELx value is zero, thus, the PCLK for
	all the peripherals is 1/4 of the SystemFrequency.)
	--  set prescaler to get 1 M counts/sec
	--  Set up 200 mS interval for MAT0.0
	-- Set Match Control function to toggle
	-- Interrupt and Reset on MR0
	-- Enable Interrupt using CMSIS function 
*/
	
	LPC_SC->PCONP BITSET(1); //power timer 1
	LPC_SC->PCLKSEL0 BITSET(2); 
	
	LPC_TIM0->MR0 BITSET(
	
	LPC_TIM0->MCR BITSET(0); //interupt and reset on mr0
	LPC_TIM0->MCR BITSET(1);
	
	NVIC_EnableIRQ(TIMER0_IRQn);



	
	
	return (TRUE);

}

/******************************************************************************
**                            End Of File
******************************************************************************/
