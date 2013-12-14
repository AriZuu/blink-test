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
    Default_Handler,                   // DMA_IRQHandler    
    Default_Handler,                   // GPIO_EVEN_IRQHandler    
    Default_Handler,                   // TIMER0_IRQHandler    
    Default_Handler,                   // USART0_RX_IRQHandler    
    Default_Handler,                   // USART0_TX_IRQHandler    
    Default_Handler,                   // ACMP0_IRQHandler    
    Default_Handler,                   // ADC0_IRQHandler    
    Default_Handler,                   // DAC0_IRQHandler    
    Default_Handler,                   // I2C0_IRQHandler    
    Default_Handler,                   // GPIO_ODD_IRQHandler    
    Default_Handler,                   // TIMER1_IRQHandler    
    Default_Handler,                   // TIMER2_IRQHandler    
    Default_Handler,                   // USART1_RX_IRQHandler    
    Default_Handler,                   // USART1_TX_IRQHandler    
    Default_Handler,                   // USART2_RX_IRQHandler    
    Default_Handler,                   // USART2_TX_IRQHandler    
    Default_Handler,                   // UART0_RX_IRQHandler    
    Default_Handler,                   // UART0_TX_IRQHandler    
    Default_Handler,                   // LEUART0_IRQHandler    
    Default_Handler,                   // LEUART1_IRQHandler    
    Default_Handler,                   // LETIMER0_IRQHandler    
    Default_Handler,                   // PCNT0_IRQHandler    
    Default_Handler,                   // PCNT1_IRQHandler    
    Default_Handler,                   // PCNT2_IRQHandler    
    Default_Handler,                   // RTC_IRQHandler    
    Default_Handler,                   // CMU_IRQHandler    
    Default_Handler,                   // VCMP_IRQHandler    
    Default_Handler,                   // LCD_IRQHandler    
    Default_Handler,                   // MSC_IRQHandler    
    Default_Handler,                   // AES_IRQHandler    
 };

