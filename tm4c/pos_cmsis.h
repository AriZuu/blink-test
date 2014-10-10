/*
 * Copyright (c) 2012-2013, Ari Suutari <ari@stonepile.fi>.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote
 *     products derived from this software without specific prior written
 *     permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifdef _DBG
#define DEBUG
#endif

#include "TIVA.h"

/*
 * Undefine register address definitions that conflict with driverlib.
 * Although the addresses are the same, they are defined differently
 * which causes compiler to complain.
 */

#undef DWT_BASE
#undef ITM_BASE
#undef NVIC_BASE
#undef WATCHDOG0_BASE
#undef WATCHDOG1_BASE
#undef GPIOA_BASE
#undef GPIOB_BASE
#undef GPIOC_BASE
#undef GPIOD_BASE
#undef SSI0_BASE
#undef SSI1_BASE
#undef SSI2_BASE
#undef SSI3_BASE
#undef UART0_BASE
#undef UART1_BASE
#undef UART2_BASE
#undef UART3_BASE
#undef UART4_BASE
#undef UART5_BASE
#undef UART6_BASE
#undef UART7_BASE
#undef I2C0_BASE
#undef I2C1_BASE
#undef I2C2_BASE
#undef I2C3_BASE
#undef GPIOE_BASE
#undef GPIOF_BASE
#undef PWM0_BASE
#undef PWM1_BASE
#undef QEI0_BASE
#undef QEI1_BASE
#undef TIMER0_BASE
#undef TIMER1_BASE
#undef TIMER2_BASE
#undef TIMER3_BASE
#undef TIMER4_BASE
#undef TIMER5_BASE
#undef WTIMER0_BASE
#undef WTIMER1_BASE
#undef ADC0_BASE
#undef ADC1_BASE
#undef COMP_BASE
#undef CAN0_BASE
#undef CAN1_BASE
#undef WTIMER2_BASE
#undef WTIMER3_BASE
#undef WTIMER4_BASE
#undef WTIMER5_BASE
#undef USB0_BASE
#undef GPIOA_AHB_BASE
#undef GPIOB_AHB_BASE
#undef GPIOC_AHB_BASE
#undef GPIOD_AHB_BASE
#undef GPIOE_AHB_BASE
#undef GPIOF_AHB_BASE
#undef EEPROM_BASE
#undef SYSEXC_BASE
#undef HIB_BASE
#undef FLASH_CTRL_BASE
#undef SYSCTL_BASE
#undef UDMA_BASE

void UART0_Handler(void);

