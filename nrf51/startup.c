/*
 * Copyright (c) 2016-2017, Ari Suutari <ari@stonepile.fi>.
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
#include "nrf51_bitfields.h"

void Default_Handler(void);

void Default_Handler()
{
  __disable_irq();
  while (1)
    ;
}

static void PORT_NAKED Reset_Handler1()
{
  NRF_POWER->RAMON |= ((POWER_RAMON_ONRAM0_RAM0On << POWER_RAMON_ONRAM0_Pos) |
                       (POWER_RAMON_ONRAM1_RAM1On << POWER_RAMON_ONRAM1_Pos));

  Reset_Handler();
}

extern unsigned int __stack[];

PORT_WEAK_HANDLER(SysTick_Handler);

PORT_WEAK_HANDLER(POWER_CLOCK_IRQHandler);
PORT_WEAK_HANDLER(RADIO_IRQHandler);
PORT_WEAK_HANDLER(UART0_IRQHandler);
PORT_WEAK_HANDLER(SPI0_TWI0_IRQHandler);
PORT_WEAK_HANDLER(SPI1_TWI1_IRQHandler);
PORT_WEAK_HANDLER(GPIOTE_IRQHandler);
PORT_WEAK_HANDLER(ADC_IRQHandler);
PORT_WEAK_HANDLER(TIMER0_IRQHandler);
PORT_WEAK_HANDLER(TIMER1_IRQHandler);
PORT_WEAK_HANDLER(TIMER2_IRQHandler);
PORT_WEAK_HANDLER(RTC0_IRQHandler);
PORT_WEAK_HANDLER(TEMP_IRQHandler);
PORT_WEAK_HANDLER(RNG_IRQHandler);
PORT_WEAK_HANDLER(ECB_IRQHandler);
PORT_WEAK_HANDLER(CCM_AAR_IRQHandler);
PORT_WEAK_HANDLER(WDT_IRQHandler);
PORT_WEAK_HANDLER(RTC1_IRQHandler);
PORT_WEAK_HANDLER(QDEC_IRQHandler);
PORT_WEAK_HANDLER(LPCOMP_IRQHandler);
PORT_WEAK_HANDLER(SWI0_IRQHandler);
PORT_WEAK_HANDLER(SWI1_IRQHandler);
PORT_WEAK_HANDLER(SWI2_IRQHandler);
PORT_WEAK_HANDLER(SWI3_IRQHandler);
PORT_WEAK_HANDLER(SWI4_IRQHandler);
PORT_WEAK_HANDLER(SWI5_IRQHandler);

PortExcHandlerFunc vectorTable[] __attribute__ ((section(".vectors"))) =
{ (PortExcHandlerFunc) __stack,        // stack pointer
    Reset_Handler1,       // code entry point
    Reset_Handler,       // NMI handler (not really)
    HardFault_Handler,    // hard fault handler (let's hope not)
    Reset_Handler,       // MemManage failt
    Reset_Handler,       // Bus fault
    UsageFault_Handler,   // Usage fault
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    SVC_Handler,          // SVC
    Reset_Handler,       // Debug monitor
    0,                    // Reserved
    PendSV_Handler,       // Context switch
    SysTick_Handler,
//---
    POWER_CLOCK_IRQHandler,
    RADIO_IRQHandler,
    UART0_IRQHandler,
    SPI0_TWI0_IRQHandler,
    SPI1_TWI1_IRQHandler,
    0,
    GPIOTE_IRQHandler,
    ADC_IRQHandler,
    TIMER0_IRQHandler,
    TIMER1_IRQHandler,
    TIMER2_IRQHandler,
    RTC0_IRQHandler,
    TEMP_IRQHandler,
    RNG_IRQHandler,
    ECB_IRQHandler,
    CCM_AAR_IRQHandler,
    WDT_IRQHandler,
    RTC1_IRQHandler,
    QDEC_IRQHandler,
    LPCOMP_IRQHandler,
    SWI0_IRQHandler,
    SWI1_IRQHandler,
    SWI2_IRQHandler,
    SWI3_IRQHandler,
    SWI4_IRQHandler,
    SWI5_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
};

