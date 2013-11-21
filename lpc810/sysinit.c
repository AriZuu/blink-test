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

void SystemInit(void)
{
	#if 0
  Chip_SystemInit();
  SystemCoreClockUpdate();
	#else
	SystemCoreClock = 12000000;
	#endif
	
}

const uint32_t OscRateIn = 0; //12000000;
const uint32_t ExtRateIn = 0;

#if PORTCFG_VECTORS == 1
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
    Default_Handler,                   // PIO0_0  Wakeup
    Default_Handler,                   // PIO0_1  Wakeup
    Default_Handler,                   // PIO0_2  Wakeup
    Default_Handler,                   // PIO0_3  Wakeup
    Default_Handler,                   // PIO0_4  Wakeup
    Default_Handler,                   // PIO0_5  Wakeup
    Default_Handler,                   // PIO0_6  Wakeup
    Default_Handler,                   // PIO0_7  Wakeup
    Default_Handler,                   // PIO0_8  Wakeup
    Default_Handler,                   // PIO0_9  Wakeup
    Default_Handler,                   // PIO0_10 Wakeup
    Default_Handler,                   // PIO0_11 Wakeup
    Default_Handler,                   // PIO1_0  Wakeup
    Default_Handler,                   // C_CAN Interrupt
    Default_Handler,                   // SPI/SSP1 Interrupt
    Default_Handler,                   // I2C0
    Default_Handler,                   // CT16B0 (16-bit Timer 0)
    Default_Handler,                   // CT16B1 (16-bit Timer 1)
    Default_Handler,                   // CT32B0 (32-bit Timer 0)
    Default_Handler,                   // CT32B1 (32-bit Timer 1)
    Default_Handler,                   // SPI/SSP0 Interrupt
    Uart_Handler,                      // UART0
    0,                                 // Reserved
    0,                                 // Reserved
    Default_Handler,                   // ADC   (A/D Converter)
    Default_Handler,                   // WDT   (Watchdog Timer)
    Default_Handler,                   // BOD   (Brownout Detect)
    0,                                 // Reserved
    Default_Handler,                   // PIO INT3
    Default_Handler,                   // PIO INT2
    Default_Handler,                   // PIO INT1
    Default_Handler,                   // PIO INT0
 };

#endif
