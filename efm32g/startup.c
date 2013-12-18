/*
 * Copyright (c) 2006-2013, Ari Suutari <ari@stonepile.fi>.
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

#include <picoos.h>

void Default_Handler(void);

void Default_Handler()
{
  __disable_irq();
  while (1)
    ;
}

extern unsigned int __stack[];

PORT_WEAK_HANDLER(SysTick_Handler);
PORT_WEAK_HANDLER(DMA_IRQHandler);
PORT_WEAK_HANDLER(GPIO_EVEN_IRQHandler);
PORT_WEAK_HANDLER(TIMER0_IRQHandler);
PORT_WEAK_HANDLER(USART0_RX_IRQHandler);
PORT_WEAK_HANDLER(USART0_TX_IRQHandler);
PORT_WEAK_HANDLER(ACMP0_IRQHandler);
PORT_WEAK_HANDLER(ADC0_IRQHandler);
PORT_WEAK_HANDLER(DAC0_IRQHandler);
PORT_WEAK_HANDLER(I2C0_IRQHandler);
PORT_WEAK_HANDLER(GPIO_ODD_IRQHandler);
PORT_WEAK_HANDLER(TIMER1_IRQHandler);
PORT_WEAK_HANDLER(TIMER2_IRQHandler);
PORT_WEAK_HANDLER(USART1_RX_IRQHandler);
PORT_WEAK_HANDLER(USART1_TX_IRQHandler);
PORT_WEAK_HANDLER(USART2_RX_IRQHandler);
PORT_WEAK_HANDLER(USART2_TX_IRQHandler);
PORT_WEAK_HANDLER(UART0_RX_IRQHandler);
PORT_WEAK_HANDLER(UART0_TX_IRQHandler);
PORT_WEAK_HANDLER(LEUART0_IRQHandler);
PORT_WEAK_HANDLER(LEUART1_IRQHandler);
PORT_WEAK_HANDLER(LETIMER0_IRQHandler);
PORT_WEAK_HANDLER(PCNT0_IRQHandler);
PORT_WEAK_HANDLER(PCNT1_IRQHandler);
PORT_WEAK_HANDLER(PCNT2_IRQHandler);
PORT_WEAK_HANDLER(RTC_IRQHandler);
PORT_WEAK_HANDLER(CMU_IRQHandler);
PORT_WEAK_HANDLER(VCMP_IRQHandler);
PORT_WEAK_HANDLER(LCD_IRQHandler);
PORT_WEAK_HANDLER(MSC_IRQHandler);
PORT_WEAK_HANDLER(AES_IRQHandler);

PortExcHandlerFunc vectorTable[] __attribute__ ((section(".vectors"))) =
{ (PortExcHandlerFunc) __stack,        // stack pointer
    Reset_Handler,                     // code entry point
    Reset_Handler,                     // NMI handler (not really)
    HardFault_Handler,                 // hard fault handler (let's hope not)
    Reset_Handler,                     // MemManage failt
    Reset_Handler,                     // Bus fault
    UsageFault_Handler,                // Usage fault
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVC
    Reset_Handler,                     // Debug monitor
    0,                                 // Reserved
    PendSV_Handler,                    // Context switch
    SysTick_Handler,
// EFM32 handlers
    DMA_IRQHandler,
    GPIO_EVEN_IRQHandler,
    TIMER0_IRQHandler,
    USART0_RX_IRQHandler,
    USART0_TX_IRQHandler,
    ACMP0_IRQHandler,
    ADC0_IRQHandler,
    DAC0_IRQHandler,
    I2C0_IRQHandler,
    GPIO_ODD_IRQHandler,
    TIMER1_IRQHandler,
    TIMER2_IRQHandler,
    USART1_RX_IRQHandler,
    USART1_TX_IRQHandler,
    USART2_RX_IRQHandler,
    USART2_TX_IRQHandler,
    UART0_RX_IRQHandler,
    UART0_TX_IRQHandler,
    LEUART0_IRQHandler,
    LEUART1_IRQHandler,
    LETIMER0_IRQHandler,
    PCNT0_IRQHandler,
    PCNT1_IRQHandler,
    PCNT2_IRQHandler,
    RTC_IRQHandler,
    CMU_IRQHandler,
    VCMP_IRQHandler,
    LCD_IRQHandler,
    MSC_IRQHandler,
    AES_IRQHandler
 };

