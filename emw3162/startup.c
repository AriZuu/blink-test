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

void Default_Handler(void);

void Default_Handler()
{
  __disable_irq();
  while (1)
    ;
}

extern unsigned int __stack[];

PORT_WEAK_HANDLER(WWDG_IRQHandler);
PORT_WEAK_HANDLER(PVD_IRQHandler);
PORT_WEAK_HANDLER(TAMP_STAMP_IRQHandler);
PORT_WEAK_HANDLER(RTC_WKUP_IRQHandler);
PORT_WEAK_HANDLER(FLASH_IRQHandler);
PORT_WEAK_HANDLER(RCC_IRQHandler);
PORT_WEAK_HANDLER(EXTI0_IRQHandler);
PORT_WEAK_HANDLER(EXTI1_IRQHandler);
PORT_WEAK_HANDLER(EXTI2_IRQHandler);
PORT_WEAK_HANDLER(EXTI3_IRQHandler);
PORT_WEAK_HANDLER(EXTI4_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream0_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream1_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream2_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream3_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream4_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream5_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream6_IRQHandler);
PORT_WEAK_HANDLER(ADC_IRQHandler);
PORT_WEAK_HANDLER(CAN1_TX_IRQHandler);
PORT_WEAK_HANDLER(CAN1_RX0_IRQHandler);
PORT_WEAK_HANDLER(CAN1_RX1_IRQHandler);
PORT_WEAK_HANDLER(CAN1_SCE_IRQHandler);
PORT_WEAK_HANDLER(EXTI9_5_IRQHandler);
PORT_WEAK_HANDLER(TIM1_BRK_TIM9_IRQHandler);
PORT_WEAK_HANDLER(TIM1_UP_TIM10_IRQHandler);
PORT_WEAK_HANDLER(TIM1_TRG_COM_TIM11_IRQHandler);
PORT_WEAK_HANDLER(TIM1_CC_IRQHandler);
PORT_WEAK_HANDLER(TIM2_IRQHandler);
PORT_WEAK_HANDLER(TIM3_IRQHandler);
PORT_WEAK_HANDLER(TIM4_IRQHandler);
PORT_WEAK_HANDLER(I2C1_EV_IRQHandler);
PORT_WEAK_HANDLER(I2C1_ER_IRQHandler);
PORT_WEAK_HANDLER(I2C2_EV_IRQHandler);
PORT_WEAK_HANDLER(I2C2_ER_IRQHandler);
PORT_WEAK_HANDLER(SPI1_IRQHandler);
PORT_WEAK_HANDLER(SPI2_IRQHandler);
PORT_WEAK_HANDLER(USART1_IRQHandler);
PORT_WEAK_HANDLER(USART2_IRQHandler);
PORT_WEAK_HANDLER(USART3_IRQHandler);
PORT_WEAK_HANDLER(EXTI15_10_IRQHandler);
PORT_WEAK_HANDLER(RTC_Alarm_IRQHandler);
PORT_WEAK_HANDLER(OTG_FS_WKUP_IRQHandler);
PORT_WEAK_HANDLER(TIM8_BRK_TIM12_IRQHandler);
PORT_WEAK_HANDLER(TIM8_UP_TIM13_IRQHandler);
PORT_WEAK_HANDLER(TIM8_TRG_COM_TIM14_IRQHandler);
PORT_WEAK_HANDLER(TIM8_CC_IRQHandler);
PORT_WEAK_HANDLER(DMA1_Stream7_IRQHandler);
PORT_WEAK_HANDLER(FSMC_IRQHandler);
PORT_WEAK_HANDLER(SDIO_IRQHandler);
PORT_WEAK_HANDLER(TIM5_IRQHandler);
PORT_WEAK_HANDLER(SPI3_IRQHandler);
PORT_WEAK_HANDLER(UART4_IRQHandler);
PORT_WEAK_HANDLER(UART5_IRQHandler);
PORT_WEAK_HANDLER(TIM6_DAC_IRQHandler);
PORT_WEAK_HANDLER(TIM7_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream0_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream1_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream2_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream3_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream4_IRQHandler);
PORT_WEAK_HANDLER(ETH_IRQHandler);
PORT_WEAK_HANDLER(ETH_WKUP_IRQHandler);
PORT_WEAK_HANDLER(CAN2_TX_IRQHandler);
PORT_WEAK_HANDLER(CAN2_RX0_IRQHandler);
PORT_WEAK_HANDLER(CAN2_RX1_IRQHandler);
PORT_WEAK_HANDLER(CAN2_SCE_IRQHandler);
PORT_WEAK_HANDLER(OTG_FS_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream5_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream6_IRQHandler);
PORT_WEAK_HANDLER(DMA2_Stream7_IRQHandler);
PORT_WEAK_HANDLER(USART6_IRQHandler);
PORT_WEAK_HANDLER(I2C3_EV_IRQHandler);
PORT_WEAK_HANDLER(I2C3_ER_IRQHandler);
PORT_WEAK_HANDLER(OTG_HS_EP1_OUT_IRQHandler);
PORT_WEAK_HANDLER(OTG_HS_EP1_IN_IRQHandler);
PORT_WEAK_HANDLER(OTG_HS_WKUP_IRQHandler);
PORT_WEAK_HANDLER(OTG_HS_IRQHandler);
PORT_WEAK_HANDLER(DCMI_IRQHandler);
PORT_WEAK_HANDLER(CRYP_IRQHandler);
PORT_WEAK_HANDLER(HASH_RNG_IRQHandler);

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
// STM32F2xx handlers
    WWDG_IRQHandler,                   // Window WatchDog                                                      
    PVD_IRQHandler,                    // PVD through EXTI Line detection                         
    TAMP_STAMP_IRQHandler,             // Tamper and TimeStamps through the EXTI line             
    RTC_WKUP_IRQHandler,               // RTC Wakeup through the EXTI line                       
    FLASH_IRQHandler,                  // FLASH                                                                  
    RCC_IRQHandler,                    // RCC                                                                      
    EXTI0_IRQHandler,                  // EXTI Line0                                           
    EXTI1_IRQHandler,                  // EXTI Line1                                             
    EXTI2_IRQHandler,                  // EXTI Line2                                             
    EXTI3_IRQHandler,                  // EXTI Line3                                             
    EXTI4_IRQHandler,                  // EXTI Line4                                             
    DMA1_Stream0_IRQHandler,           // DMA1 Stream 0                                  
    DMA1_Stream1_IRQHandler,           // DMA1 Stream 1                                   
    DMA1_Stream2_IRQHandler,           // DMA1 Stream 2                                   
    DMA1_Stream3_IRQHandler,           // DMA1 Stream 3                                   
    DMA1_Stream4_IRQHandler,           // DMA1 Stream 4                                   
    DMA1_Stream5_IRQHandler,           // DMA1 Stream 5                                   
    DMA1_Stream6_IRQHandler,           // DMA1 Stream 6                                   
    ADC_IRQHandler,                    // ADC1, ADC2 and ADC3s                            
    CAN1_TX_IRQHandler,                // CAN1 TX                                               
    CAN1_RX0_IRQHandler,               // CAN1 RX0                                               
    CAN1_RX1_IRQHandler,               // CAN1 RX1                                               
    CAN1_SCE_IRQHandler,               // CAN1 SCE                                               
    EXTI9_5_IRQHandler,                // External Line[9:5]s                                    
    TIM1_BRK_TIM9_IRQHandler,          // TIM1 Break and TIM9                   
    TIM1_UP_TIM10_IRQHandler,          // TIM1 Update and TIM10                 
    TIM1_TRG_COM_TIM11_IRQHandler,     // TIM1 Trigger and Commutation and TIM11 
    TIM1_CC_IRQHandler,                // TIM1 Capture Compare                                   
    TIM2_IRQHandler,                   // TIM2                                            
    TIM3_IRQHandler,                   // TIM3                                            
    TIM4_IRQHandler,                   // TIM4                                            
    I2C1_EV_IRQHandler,                // I2C1 Event                                             
    I2C1_ER_IRQHandler,                // I2C1 Error                                             
    I2C2_EV_IRQHandler,                // I2C2 Event                                             
    I2C2_ER_IRQHandler,                // I2C2 Error                                               
    SPI1_IRQHandler,                   // SPI1                                            
    SPI2_IRQHandler,                   // SPI2                                            
    USART1_IRQHandler,                 // USART1                                          
    USART2_IRQHandler,                 // USART2                                          
    USART3_IRQHandler,                 // USART3                                          
    EXTI15_10_IRQHandler,              // External Line[15:10]s                                  
    RTC_Alarm_IRQHandler,              // RTC Alarm (A and B) through EXTI Line                  
    OTG_FS_WKUP_IRQHandler,            // USB OTG FS Wakeup through EXTI line                        
    TIM8_BRK_TIM12_IRQHandler,         // TIM8 Break and TIM12                  
    TIM8_UP_TIM13_IRQHandler,          // TIM8 Update and TIM13                 
    TIM8_TRG_COM_TIM14_IRQHandler,     // TIM8 Trigger and Commutation and TIM14 
    TIM8_CC_IRQHandler,                // TIM8 Capture Compare                                   
    DMA1_Stream7_IRQHandler,           // DMA1 Stream7                                           
    FSMC_IRQHandler,                   // FSMC                                            
    SDIO_IRQHandler,                   // SDIO                                            
    TIM5_IRQHandler,                   // TIM5                                            
    SPI3_IRQHandler,                   // SPI3                                            
    UART4_IRQHandler,                  // UART4                                           
    UART5_IRQHandler,                  // UART5                                           
    TIM6_DAC_IRQHandler,               // TIM6 and DAC1&2 underrun errors                    
    TIM7_IRQHandler,                   // TIM7                         
    DMA2_Stream0_IRQHandler,           // DMA2 Stream 0                                   
    DMA2_Stream1_IRQHandler,           // DMA2 Stream 1                                   
    DMA2_Stream2_IRQHandler,           // DMA2 Stream 2                                   
    DMA2_Stream3_IRQHandler,           // DMA2 Stream 3                                   
    DMA2_Stream4_IRQHandler,           // DMA2 Stream 4                                   
    ETH_IRQHandler,                    // Ethernet                                        
    ETH_WKUP_IRQHandler,               // Ethernet Wakeup through EXTI line                      
    CAN2_TX_IRQHandler,                // CAN2 TX                                                
    CAN2_RX0_IRQHandler,               // CAN2 RX0                                               
    CAN2_RX1_IRQHandler,               // CAN2 RX1                                               
    CAN2_SCE_IRQHandler,               // CAN2 SCE                                               
    OTG_FS_IRQHandler,                 // USB OTG FS                                      
    DMA2_Stream5_IRQHandler,           // DMA2 Stream 5                                   
    DMA2_Stream6_IRQHandler,           // DMA2 Stream 6                                   
    DMA2_Stream7_IRQHandler,           // DMA2 Stream 7                                   
    USART6_IRQHandler,                 // USART6                                           
    I2C3_EV_IRQHandler,                // I2C3 event                                             
    I2C3_ER_IRQHandler,                // I2C3 error                                             
    OTG_HS_EP1_OUT_IRQHandler,         // USB OTG HS End Point 1 Out                      
    OTG_HS_EP1_IN_IRQHandler,          // USB OTG HS End Point 1 In                       
    OTG_HS_WKUP_IRQHandler,            // USB OTG HS Wakeup through EXTI                          
    OTG_HS_IRQHandler,                 // USB OTG HS                                      
    DCMI_IRQHandler,                   // DCMI                                            
    CRYP_IRQHandler,                   // CRYP crypto                                     
    HASH_RNG_IRQHandler                // Hash and Rng                 
};
