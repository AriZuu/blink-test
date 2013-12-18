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
#include <stdbool.h>
#include <em_chip.h>
#include <em_cmu.h>
#include <em_gpio.h>
#include <em_dbg.h>
#include "test.h"

#define LED1_PORT 0      // Port for led
#define LED2_PORT 0
#define LED3_PORT 0

#define LED1_BIT 2       // Bit on port for led
#define LED2_BIT 3       // Bit on port for led
#define LED3_BIT 8
#define LED_ON 1        // Level to set port to turn on led
#define LED_OFF 0       // Level to set port to turn off led

void testLedSet(LED_t led, bool on)
{
  switch (led)
  {
  case Red:
    if (on)
      GPIO_PinOutClear(gpioPortA, 0);
    else
      GPIO_PinOutSet(gpioPortA, 0);
    break;

  case Green:
    break;

  case Yellow:
    break;
  }
}

void testInitIO()
{
  CMU_ClockEnable(cmuClock_GPIO, true);

/*
 * Button.
 */
  GPIO_PinModeSet(gpioPortA, 1, gpioModeInputPullFilter, 0); 

/*
 * Led.
 */
  GPIO_PinModeSet(gpioPortA, 0, gpioModePushPullDrive, 0);
  GPIO_DriveModeSet(gpioPortA, gpioDriveModeHigh);
}

int main(int argc, char **argv)
{
/*
 * Initalize chip.
 */
  CHIP_Init();

/* 
 * Use XT oscillator, disable internal RC osc.
 */
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
  CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);
  SystemCoreClockUpdate();

  // Allow deep sleep.

  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;    /* Configure Cortex-M for deep sleep  */

#if PORTCFG_CONOUT_ITM == 1
#ifdef _DBG
  if (DBG_Connected()) {

    CMU_ClockEnable(cmuClock_GPIO, true);
    DBG_SWOEnable(0);

    /* Enable trace in core debug, taken from Energy Aware Commander */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    ITM->LAR  = 0xC5ACCE55;
    ITM->TER  = 0x0;
    ITM->TCR  = 0x0;
    TPI->SPPR = 2;
    TPI->ACPR = 0xf;
    ITM->TPR  = 0x0;
    DWT->CTRL = 0x400003FE;
    ITM->TCR  = 0x0001000D;
    TPI->FFCR = 0x00000100;
    ITM->TER  = 0x1;

  }
#endif
#endif

  testStart();
  return 0;
}
