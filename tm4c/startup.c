/*
 * Copyright (c) 2006-2014, Ari Suutari <ari@stonepile.fi>.
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

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/fpu.h"
#include "driverlib/debug.h"

uint32_t SystemCoreClock;

void SystemInit()
{
  FPUEnable();
  FPULazyStackingEnable();

#ifdef SYSTEM_TM4C123_H
  SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                     SYSCTL_XTAL_16MHZ);

  SystemCoreClock = SysCtlClockGet();
#endif

#ifdef SYSTEM_TM4C129_H

  SystemCoreClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                        SYSCTL_OSC_MAIN |
                                        SYSCTL_USE_PLL |
                                        SYSCTL_CFG_VCO_480), 120000000);
#endif
}
void Default_Handler(void);

void Default_Handler()
{
  __disable_irq();
  while (1)
    ;
}

extern void __error__(char *file, uint32_t line)
{
  p_pos_assert("tivaware", file, line);
}

extern unsigned int __stack[];

#ifdef SYSTEM_TM4C123_H

PORT_WEAK_HANDLER(SysTick_Handler);
PORT_WEAK_HANDLER(GPIOA_Handler);
PORT_WEAK_HANDLER(GPIOB_Handler);
PORT_WEAK_HANDLER(GPIOC_Handler);
PORT_WEAK_HANDLER(GPIOD_Handler);
PORT_WEAK_HANDLER(GPIOE_Handler);
PORT_WEAK_HANDLER(UART0_Handler);
PORT_WEAK_HANDLER(UART1_Handler);
PORT_WEAK_HANDLER(SSI0_Handler);
PORT_WEAK_HANDLER(I2C0_Handler);
PORT_WEAK_HANDLER(PWM0_Fault_Handler);
PORT_WEAK_HANDLER(PWM0_0_Handler);
PORT_WEAK_HANDLER(PWM0_1_Handler);
PORT_WEAK_HANDLER(PWM0_2_Handler);
PORT_WEAK_HANDLER(QEI0_Handler);
PORT_WEAK_HANDLER(ADC0_S0_Handler);
PORT_WEAK_HANDLER(ADC0_S1_Handler);
PORT_WEAK_HANDLER(ADC0_S2_Handler);
PORT_WEAK_HANDLER(ADC0_S3_Handler);
PORT_WEAK_HANDLER(WDT0_Handler);
PORT_WEAK_HANDLER(TIMER0A_Handler);
PORT_WEAK_HANDLER(TIMER0B_Handler);
PORT_WEAK_HANDLER(TIMER1A_Handler);
PORT_WEAK_HANDLER(TIMER1B_Handler);
PORT_WEAK_HANDLER(TIMER2A_Handler);
PORT_WEAK_HANDLER(TIMER2B_Handler);
PORT_WEAK_HANDLER(COMP0_Handler);
PORT_WEAK_HANDLER(COMP1_Handler);
PORT_WEAK_HANDLER(COMP2_Handler);
PORT_WEAK_HANDLER(SYSCTL_Handler);
PORT_WEAK_HANDLER(FLASH_Handler);
PORT_WEAK_HANDLER(GPIOF_Handler);
PORT_WEAK_HANDLER(GPIOG_Handler);
PORT_WEAK_HANDLER(GPIOH_Handler);
PORT_WEAK_HANDLER(UART2_Handler);
PORT_WEAK_HANDLER(SSI1_Handler);
PORT_WEAK_HANDLER(TIMER3A_Handler);
PORT_WEAK_HANDLER(TIMER3B_Handler);
PORT_WEAK_HANDLER(I2C1_Handler);
PORT_WEAK_HANDLER(QEI1_Handler);
PORT_WEAK_HANDLER(CAN0_Handler);
PORT_WEAK_HANDLER(CAN1_Handler);
PORT_WEAK_HANDLER(HIB_Handler);
PORT_WEAK_HANDLER(USB0_Handler);
PORT_WEAK_HANDLER(PWM0_3_Handler);
PORT_WEAK_HANDLER(UDMA_Handler);
PORT_WEAK_HANDLER(UDMAERR_Handler);
PORT_WEAK_HANDLER(ADC1_S0_Handler);
PORT_WEAK_HANDLER(ADC1_S1_Handler);
PORT_WEAK_HANDLER(ADC1_S2_Handler);
PORT_WEAK_HANDLER(ADC1_S3_Handler);
PORT_WEAK_HANDLER(GPIOJ_Handler);
PORT_WEAK_HANDLER(GPIOK_Handler);
PORT_WEAK_HANDLER(GPIOL_Handler);
PORT_WEAK_HANDLER(SSI2_Handler);
PORT_WEAK_HANDLER(SSI3_Handler);
PORT_WEAK_HANDLER(UART3_Handler);
PORT_WEAK_HANDLER(UART4_Handler);
PORT_WEAK_HANDLER(UART5_Handler);
PORT_WEAK_HANDLER(UART6_Handler);
PORT_WEAK_HANDLER(UART7_Handler);
PORT_WEAK_HANDLER(I2C2_Handler);
PORT_WEAK_HANDLER(I2C3_Handler);
PORT_WEAK_HANDLER(TIMER4A_Handler);
PORT_WEAK_HANDLER(TIMER4B_Handler);
PORT_WEAK_HANDLER(TIMER5A_Handler);
PORT_WEAK_HANDLER(TIMER5B_Handler);
PORT_WEAK_HANDLER(WTIMER0A_Handler);
PORT_WEAK_HANDLER(WTIMER0B_Handler);
PORT_WEAK_HANDLER(WTIMER1A_Handler);
PORT_WEAK_HANDLER(WTIMER1B_Handler);
PORT_WEAK_HANDLER(WTIMER2A_Handler);
PORT_WEAK_HANDLER(WTIMER2B_Handler);
PORT_WEAK_HANDLER(WTIMER3A_Handler);
PORT_WEAK_HANDLER(WTIMER3B_Handler);
PORT_WEAK_HANDLER(WTIMER4A_Handler);
PORT_WEAK_HANDLER(WTIMER4B_Handler);
PORT_WEAK_HANDLER(WTIMER5A_Handler);
PORT_WEAK_HANDLER(WTIMER5B_Handler);
PORT_WEAK_HANDLER(FPU_Handler);
PORT_WEAK_HANDLER(I2C4_Handler);
PORT_WEAK_HANDLER(I2C5_Handler);
PORT_WEAK_HANDLER(GPIOM_Handler);
PORT_WEAK_HANDLER(GPION_Handler);
PORT_WEAK_HANDLER(QEI2_Handler);
PORT_WEAK_HANDLER(GPIOP0_Handler);
PORT_WEAK_HANDLER(GPIOP1_Handler);
PORT_WEAK_HANDLER(GPIOP2_Handler);
PORT_WEAK_HANDLER(GPIOP3_Handler);
PORT_WEAK_HANDLER(GPIOP4_Handler);
PORT_WEAK_HANDLER(GPIOP5_Handler);
PORT_WEAK_HANDLER(GPIOP6_Handler);
PORT_WEAK_HANDLER(GPIOP7_Handler);
PORT_WEAK_HANDLER(GPIOQ0_Handler);
PORT_WEAK_HANDLER(GPIOQ1_Handler);
PORT_WEAK_HANDLER(GPIOQ2_Handler);
PORT_WEAK_HANDLER(GPIOQ3_Handler);
PORT_WEAK_HANDLER(GPIOQ4_Handler);
PORT_WEAK_HANDLER(GPIOQ5_Handler);
PORT_WEAK_HANDLER(GPIOQ6_Handler);
PORT_WEAK_HANDLER(GPIOQ7_Handler);
PORT_WEAK_HANDLER(GPIOR_Handler);
PORT_WEAK_HANDLER(GPIOS_Handler);
PORT_WEAK_HANDLER(PWM1_0_Handler);
PORT_WEAK_HANDLER(PWM1_1_Handler);
PORT_WEAK_HANDLER(PWM1_2_Handler);
PORT_WEAK_HANDLER(PWM1_3_Handler);
PORT_WEAK_HANDLER(PWM1_Fault_Handler);

PortExcHandlerFunc vectorTable[] __attribute__ ((section(".vectors"))) =
{ (PortExcHandlerFunc) __stack,        // stack pointer
    Reset_Handler,        // code entry point
    Reset_Handler,        // NMI handler (not really)
    HardFault_Handler,    // hard fault handler (let's hope not)
    Reset_Handler,        // MemManage failt
    Reset_Handler,        // Bus fault
    UsageFault_Handler,   // Usage fault
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    SVC_Handler,          // SVC
    Reset_Handler,        // Debug monitor
    0,                    // Reserved
    PendSV_Handler,       // Context switch
    SysTick_Handler,
    GPIOA_Handler,        // GPIO Port A
    GPIOB_Handler,        // GPIO Port B
    GPIOC_Handler,        // GPIO Port C
    GPIOD_Handler,        // GPIO Port D
    GPIOE_Handler,        // GPIO Port E
    UART0_Handler,        // UART0 Rx and Tx
    UART1_Handler,        // UART1 Rx and Tx
    SSI0_Handler,         // SSI0 Rx and Tx
    I2C0_Handler,         // I2C0 Master and Slave
    PWM0_Fault_Handler,   // PWM Fault
    PWM0_0_Handler,       // PWM Generator 0
    PWM0_1_Handler,       // PWM Generator 1
    PWM0_2_Handler,       // PWM Generator 2
    QEI0_Handler,         // Quadrature Encoder 0
    ADC0_S0_Handler,      // ADC Sequence 0
    ADC0_S1_Handler,      // ADC Sequence 1
    ADC0_S2_Handler,      // ADC Sequence 2
    ADC0_S3_Handler,      // ADC Sequence 3
    WDT0_Handler,         // Watchdog timer
    TIMER0A_Handler,      // Timer 0 subtimer A
    TIMER0B_Handler,      // Timer 0 subtimer B
    TIMER1A_Handler,      // Timer 1 subtimer A
    TIMER1B_Handler,      // Timer 1 subtimer B
    TIMER2A_Handler,      // Timer 2 subtimer A
    TIMER2B_Handler,      // Timer 2 subtimer B
    COMP0_Handler,        // Analog Comparator 0
    COMP1_Handler,        // Analog Comparator 1
    COMP2_Handler,        // Analog Comparator 2
    SYSCTL_Handler,       // System Control (PLL, OSC, BO)
    FLASH_Handler,        // FLASH Control
    GPIOF_Handler,        // GPIO Port F
    GPIOG_Handler,        // GPIO Port G
    GPIOH_Handler,        // GPIO Port H
    UART2_Handler,        // UART2 Rx and Tx
    SSI1_Handler,         // SSI1 Rx and Tx
    TIMER3A_Handler,      // Timer 3 subtimer A
    TIMER3B_Handler,      // Timer 3 subtimer B
    I2C1_Handler,         // I2C1 Master and Slave
    QEI1_Handler,         // Quadrature Encoder 1
    CAN0_Handler,         // CAN0
    CAN1_Handler,         // CAN1
    0,                    // Reserved
    0,                    // Reserved
    HIB_Handler,          // Hibernate
    USB0_Handler,         // USB0
    PWM0_3_Handler,       // PWM Generator 3
    UDMA_Handler,         // uDMA Software Transfer
    UDMAERR_Handler,      // uDMA Error
    ADC1_S0_Handler,      // ADC1 Sequence 0
    ADC1_S1_Handler,      // ADC1 Sequence 1
    ADC1_S2_Handler,      // ADC1 Sequence 2
    ADC1_S3_Handler,      // ADC1 Sequence 3
    0,                    // Reserved
    0,                    // Reserved
    GPIOJ_Handler,        // GPIO Port J
    GPIOK_Handler,        // GPIO Port K
    GPIOL_Handler,        // GPIO Port L
    SSI2_Handler,         // SSI2 Rx and Tx
    SSI3_Handler,         // SSI3 Rx and Tx
    UART3_Handler,        // UART3 Rx and Tx
    UART4_Handler,        // UART4 Rx and Tx
    UART5_Handler,        // UART5 Rx and Tx
    UART6_Handler,        // UART6 Rx and Tx
    UART7_Handler,        // UART7 Rx and Tx
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    I2C2_Handler,         // I2C2 Master and Slave
    I2C3_Handler,         // I2C3 Master and Slave
    TIMER4A_Handler,      // Timer 4 subtimer A
    TIMER4B_Handler,      // Timer 4 subtimer B
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    TIMER5A_Handler,      // Timer 5 subtimer A
    TIMER5B_Handler,      // Timer 5 subtimer B
    WTIMER0A_Handler,     // Wide Timer 0 subtimer A
    WTIMER0B_Handler,     // Wide Timer 0 subtimer B
    WTIMER1A_Handler,     // Wide Timer 1 subtimer A
    WTIMER1B_Handler,     // Wide Timer 1 subtimer B
    WTIMER2A_Handler,     // Wide Timer 2 subtimer A
    WTIMER2B_Handler,     // Wide Timer 2 subtimer B
    WTIMER3A_Handler,     // Wide Timer 3 subtimer A
    WTIMER3B_Handler,     // Wide Timer 3 subtimer B
    WTIMER4A_Handler,     // Wide Timer 4 subtimer A
    WTIMER4B_Handler,     // Wide Timer 4 subtimer B
    WTIMER5A_Handler,     // Wide Timer 5 subtimer A
    WTIMER5B_Handler,     // Wide Timer 5 subtimer B
    FPU_Handler,          // FPU
    0,                    // Reserved
    0,                    // Reserved
    I2C4_Handler,         // I2C4 Master and Slave
    I2C5_Handler,         // I2C5 Master and Slave
    GPIOM_Handler,        // GPIO Port M
    GPION_Handler,        // GPIO Port N
    QEI2_Handler,         // Quadrature Encoder 2
    0,                    // Reserved
    0,                    // Reserved
    GPIOP0_Handler,       // GPIO Port P (Summary or P0)
    GPIOP1_Handler,       // GPIO Port P1
    GPIOP2_Handler,       // GPIO Port P2
    GPIOP3_Handler,       // GPIO Port P3
    GPIOP4_Handler,       // GPIO Port P4
    GPIOP5_Handler,       // GPIO Port P5
    GPIOP6_Handler,       // GPIO Port P6
    GPIOP7_Handler,       // GPIO Port P7
    GPIOQ0_Handler,       // GPIO Port Q (Summary or Q0)
    GPIOQ1_Handler,       // GPIO Port Q1
    GPIOQ2_Handler,       // GPIO Port Q2
    GPIOQ3_Handler,       // GPIO Port Q3
    GPIOQ4_Handler,       // GPIO Port Q4
    GPIOQ5_Handler,       // GPIO Port Q5
    GPIOQ6_Handler,       // GPIO Port Q6
    GPIOQ7_Handler,       // GPIO Port Q7
    GPIOR_Handler,        // GPIO Port R
    GPIOS_Handler,        // GPIO Port S
    PWM1_0_Handler,       // PWM 1 Generator 0
    PWM1_1_Handler,       // PWM 1 Generator 1
    PWM1_2_Handler,       // PWM 1 Generator 2
    PWM1_3_Handler,       // PWM 1 Generator 3
    PWM1_Fault_Handler,   // PWM 1 Fault
};
#else
#ifdef SYSTEM_TM4C129_H
PORT_WEAK_HANDLER(SysTick_Handler);
PORT_WEAK_HANDLER(GPIOA_Handler);
PORT_WEAK_HANDLER(GPIOB_Handler);
PORT_WEAK_HANDLER(GPIOC_Handler);
PORT_WEAK_HANDLER(GPIOD_Handler);
PORT_WEAK_HANDLER(GPIOE_Handler);
PORT_WEAK_HANDLER(UART0_Handler);
PORT_WEAK_HANDLER(UART1_Handler);
PORT_WEAK_HANDLER(SSI0_Handler);
PORT_WEAK_HANDLER(I2C0_Handler);
PORT_WEAK_HANDLER(PWM0_Fault_Handler);
PORT_WEAK_HANDLER(PWM0_0_Handler);
PORT_WEAK_HANDLER(PWM0_1_Handler);
PORT_WEAK_HANDLER(PWM0_2_Handler);
PORT_WEAK_HANDLER(QEI0_Handler);
PORT_WEAK_HANDLER(ADC0_S0_Handler);
PORT_WEAK_HANDLER(ADC0_S1_Handler);
PORT_WEAK_HANDLER(ADC0_S2_Handler);
PORT_WEAK_HANDLER(ADC0_S3_Handler);
PORT_WEAK_HANDLER(WDT0_Handler);
PORT_WEAK_HANDLER(TIMER0A_Handler);
PORT_WEAK_HANDLER(TIMER0B_Handler);
PORT_WEAK_HANDLER(TIMER1A_Handler);
PORT_WEAK_HANDLER(TIMER1B_Handler);
PORT_WEAK_HANDLER(TIMER2A_Handler);
PORT_WEAK_HANDLER(TIMER2B_Handler);
PORT_WEAK_HANDLER(COMP0_Handler);
PORT_WEAK_HANDLER(COMP1_Handler);
PORT_WEAK_HANDLER(COMP2_Handler);
PORT_WEAK_HANDLER(SYSCTL_Handler);
PORT_WEAK_HANDLER(FLASH_Handler);
PORT_WEAK_HANDLER(GPIOF_Handler);
PORT_WEAK_HANDLER(GPIOG_Handler);
PORT_WEAK_HANDLER(GPIOH_Handler);
PORT_WEAK_HANDLER(UART2_Handler);
PORT_WEAK_HANDLER(SSI1_Handler);
PORT_WEAK_HANDLER(TIMER3A_Handler);
PORT_WEAK_HANDLER(TIMER3B_Handler);
PORT_WEAK_HANDLER(I2C1_Handler);
PORT_WEAK_HANDLER(CAN0_Handler);
PORT_WEAK_HANDLER(CAN1_Handler);
PORT_WEAK_HANDLER(ENET_Handler);
PORT_WEAK_HANDLER(HIB_Handler);
PORT_WEAK_HANDLER(USB0_Handler);
PORT_WEAK_HANDLER(PWM0_3_Handler);
PORT_WEAK_HANDLER(UDMA_Handler);
PORT_WEAK_HANDLER(UDMAERR_Handler);
PORT_WEAK_HANDLER(ADC1_S0_Handler);
PORT_WEAK_HANDLER(ADC1_S1_Handler);
PORT_WEAK_HANDLER(ADC1_S2_Handler);
PORT_WEAK_HANDLER(ADC1_S3_Handler);
PORT_WEAK_HANDLER(EBUS0_Handler);
PORT_WEAK_HANDLER(GPIOJ_Handler);
PORT_WEAK_HANDLER(GPIOK_Handler);
PORT_WEAK_HANDLER(GPIOL_Handler);
PORT_WEAK_HANDLER(SSI2_Handler);
PORT_WEAK_HANDLER(SSI3_Handler);
PORT_WEAK_HANDLER(UART3_Handler);
PORT_WEAK_HANDLER(UART4_Handler);
PORT_WEAK_HANDLER(UART5_Handler);
PORT_WEAK_HANDLER(UART6_Handler);
PORT_WEAK_HANDLER(UART7_Handler);
PORT_WEAK_HANDLER(I2C2_Handler);
PORT_WEAK_HANDLER(I2C3_Handler);
PORT_WEAK_HANDLER(TIMER4A_Handler);
PORT_WEAK_HANDLER(TIMER4B_Handler);
PORT_WEAK_HANDLER(TIMER5A_Handler);
PORT_WEAK_HANDLER(TIMER5B_Handler);
PORT_WEAK_HANDLER(FPU_Handler);
PORT_WEAK_HANDLER(I2C4_Handler);
PORT_WEAK_HANDLER(I2C5_Handler);
PORT_WEAK_HANDLER(GPIOM_Handler);
PORT_WEAK_HANDLER(GPION_Handler);
PORT_WEAK_HANDLER(TAMPER_Handler);
PORT_WEAK_HANDLER(GPIOP0_Handler);
PORT_WEAK_HANDLER(GPIOP1_Handler);
PORT_WEAK_HANDLER(GPIOP2_Handler);
PORT_WEAK_HANDLER(GPIOP3_Handler);
PORT_WEAK_HANDLER(GPIOP4_Handler);
PORT_WEAK_HANDLER(GPIOP5_Handler);
PORT_WEAK_HANDLER(GPIOP6_Handler);
PORT_WEAK_HANDLER(GPIOP7_Handler);
PORT_WEAK_HANDLER(GPIOQ0_Handler);
PORT_WEAK_HANDLER(GPIOQ1_Handler);
PORT_WEAK_HANDLER(GPIOQ2_Handler);
PORT_WEAK_HANDLER(GPIOQ3_Handler);
PORT_WEAK_HANDLER(GPIOQ4_Handler);
PORT_WEAK_HANDLER(GPIOQ5_Handler);
PORT_WEAK_HANDLER(GPIOQ6_Handler);
PORT_WEAK_HANDLER(GPIOQ7_Handler);
PORT_WEAK_HANDLER(GPIOR_Handler);
PORT_WEAK_HANDLER(GPIOS_Handler);
PORT_WEAK_HANDLER(SHA0_Handler);
PORT_WEAK_HANDLER(AES0_Handler);
PORT_WEAK_HANDLER(DES0_Handler);
PORT_WEAK_HANDLER(LCD0_Handler);
PORT_WEAK_HANDLER(TIMER6A_Handler);
PORT_WEAK_HANDLER(TIMER6B_Handler);
PORT_WEAK_HANDLER(TIMER7A_Handler);
PORT_WEAK_HANDLER(TIMER7B_Handler);
PORT_WEAK_HANDLER(I2C6_Handler);
PORT_WEAK_HANDLER(I2C7_Handler);
PORT_WEAK_HANDLER(OW0_Handler);
PORT_WEAK_HANDLER(I2C8_Handler);
PORT_WEAK_HANDLER(I2C9_Handler);
PORT_WEAK_HANDLER(GPIOT_Handler);

PortExcHandlerFunc vectorTable[] __attribute__ ((section(".vectors"))) =
{ (PortExcHandlerFunc) __stack,        // stack pointer
    Reset_Handler,        // code entry point
    Reset_Handler,        // NMI handler (not really)
    HardFault_Handler,    // hard fault handler (let's hope not)
    Reset_Handler,        // MemManage failt
    Reset_Handler,        // Bus fault
    UsageFault_Handler,   // Usage fault
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    SVC_Handler,          // SVC
    Reset_Handler,        // Debug monitor
    0,                    // Reserved
    PendSV_Handler,       // Context switch
    SysTick_Handler,
    GPIOA_Handler,        // GPIO Port A
    GPIOB_Handler,        // GPIO Port B
    GPIOC_Handler,        // GPIO Port C
    GPIOD_Handler,        // GPIO Port D
    GPIOE_Handler,        // GPIO Port E
    UART0_Handler,        // UART0 Rx and Tx
    UART1_Handler,        // UART1 Rx and Tx
    SSI0_Handler,         // SSI0 Rx and Tx
    I2C0_Handler,         // I2C0 Master and Slave
    PWM0_Fault_Handler,   // PWM Fault
    PWM0_0_Handler,       // PWM Generator 0
    PWM0_1_Handler,       // PWM Generator 1
    PWM0_2_Handler,       // PWM Generator 2
    QEI0_Handler,         // Quadrature Encoder 0
    ADC0_S0_Handler,      // ADC Sequence 0
    ADC0_S1_Handler,      // ADC Sequence 1
    ADC0_S2_Handler,      // ADC Sequence 2
    ADC0_S3_Handler,      // ADC Sequence 3
    WDT0_Handler,         // Watchdog timer
    TIMER0A_Handler,      // Timer 0 subtimer A
    TIMER0B_Handler,      // Timer 0 subtimer B
    TIMER1A_Handler,      // Timer 1 subtimer A
    TIMER1B_Handler,      // Timer 1 subtimer B
    TIMER2A_Handler,      // Timer 2 subtimer A
    TIMER2B_Handler,      // Timer 2 subtimer B
    COMP0_Handler,        // Analog Comparator 0
    COMP1_Handler,        // Analog Comparator 1
    COMP2_Handler,        // Analog Comparator 2
    SYSCTL_Handler,       // System Control (PLL, OSC, BO)
    FLASH_Handler,        // FLASH Control
    GPIOF_Handler,        // GPIO Port F
    GPIOG_Handler,        // GPIO Port G
    GPIOH_Handler,        // GPIO Port H
    UART2_Handler,        // UART2 Rx and Tx
    SSI1_Handler,         // SSI1 Rx and Tx
    TIMER3A_Handler,      // Timer 3 subtimer A
    TIMER3B_Handler,      // Timer 3 subtimer B
    I2C1_Handler,         // I2C1 Master and Slave
    CAN0_Handler,         // CAN0
    CAN1_Handler,         // CAN1
    ENET_Handler,         // Ethernet
    HIB_Handler,          // Hibernate
    USB0_Handler,         // USB0
    PWM0_3_Handler,       // PWM Generator 3
    UDMA_Handler,         // uDMA Software Transfer
    UDMAERR_Handler,      // uDMA Error
    ADC1_S0_Handler,      // ADC1 Sequence 0
    ADC1_S1_Handler,      // ADC1 Sequence 1
    ADC1_S2_Handler,      // ADC1 Sequence 2
    ADC1_S3_Handler,      // ADC1 Sequence 3
    EBUS0_Handler,        // External Bus Interface 0
    GPIOJ_Handler,        // GPIO Port J
    GPIOK_Handler,        // GPIO Port K
    GPIOL_Handler,        // GPIO Port L
    SSI2_Handler,         // SSI2 Rx and Tx
    SSI3_Handler,         // SSI3 Rx and Tx
    UART3_Handler,        // UART3 Rx and Tx
    UART4_Handler,        // UART4 Rx and Tx
    UART5_Handler,        // UART5 Rx and Tx
    UART6_Handler,        // UART6 Rx and Tx
    UART7_Handler,        // UART7 Rx and Tx
    I2C2_Handler,         // I2C2 Master and Slave
    I2C3_Handler,         // I2C3 Master and Slave
    TIMER4A_Handler,      // Timer 4 subtimer A
    TIMER4B_Handler,      // Timer 4 subtimer B
    TIMER5A_Handler,      // Timer 5 subtimer A
    TIMER5B_Handler,      // Timer 5 subtimer B
    FPU_Handler,          // FPU
    0,                    // Reserved
    0,                    // Reserved
    I2C4_Handler,         // I2C4 Master and Slave
    I2C5_Handler,         // I2C5 Master and Slave
    GPIOM_Handler,        // GPIO Port M
    GPION_Handler,        // GPIO Port N
    0,                    // Reserved
    TAMPER_Handler,       // Tamper
    GPIOP0_Handler,       // GPIO Port P (Summary or P0)
    GPIOP1_Handler,       // GPIO Port P1
    GPIOP2_Handler,       // GPIO Port P2
    GPIOP3_Handler,       // GPIO Port P3
    GPIOP4_Handler,       // GPIO Port P4
    GPIOP5_Handler,       // GPIO Port P5
    GPIOP6_Handler,       // GPIO Port P6
    GPIOP7_Handler,       // GPIO Port P7
    GPIOQ0_Handler,       // GPIO Port Q (Summary or Q0)
    GPIOQ1_Handler,       // GPIO Port Q1
    GPIOQ2_Handler,       // GPIO Port Q2
    GPIOQ3_Handler,       // GPIO Port Q3
    GPIOQ4_Handler,       // GPIO Port Q4
    GPIOQ5_Handler,       // GPIO Port Q5
    GPIOQ6_Handler,       // GPIO Port Q6
    GPIOQ7_Handler,       // GPIO Port Q7
    GPIOR_Handler,        // GPIO Port R
    GPIOS_Handler,        // GPIO Port S
    SHA0_Handler,         // SHA/MD5 0
    AES0_Handler,         // AES 0
    DES0_Handler,         // DES3DES 0
    LCD0_Handler,         // LCD Controller 0
    TIMER6A_Handler,      // Timer 6 subtimer A
    TIMER6B_Handler,      // Timer 6 subtimer B
    TIMER7A_Handler,      // Timer 7 subtimer A
    TIMER7B_Handler,      // Timer 7 subtimer B
    I2C6_Handler,         // I2C6 Master and Slave
    I2C7_Handler,         // I2C7 Master and Slave
    0,                    // HIM Scan Matrix Keyboard 0
    OW0_Handler,          // One Wire 0
    0,                    // HIM PS/2 0
    0,                    // HIM LED Sequencer 0
    0,                    // HIM Consumer IR 0
    I2C8_Handler,         // I2C8 Master and Slave
    I2C9_Handler,         // I2C9 Master and Slave
    GPIOT_Handler,        // GPIO Port T
};

#else
#error Unsupported tiva chip
#endif
#endif
