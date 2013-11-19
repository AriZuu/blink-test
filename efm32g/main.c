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
      GPIO_PinOutSet(gpioPortA, 0);
    else
      GPIO_PinOutClear(gpioPortA, 0);
    break;

  case Green:
    break;

  case Yellow:
    break;
  }
}

void testInitIO()
{
#if 0
  Chip_GPIO_Init(LPC_GPIO);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED1_PORT, LED1_BIT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED2_PORT, LED2_BIT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO, LED3_PORT, LED3_BIT);
#endif
  CMU_ClockEnable(cmuClock_GPIO, true);

/*
 * Button.
 */
#if 0
        /* Configure button PA1, as input with pull up */
        cmu->HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO; // turn on clock
        gpio->P[0].MODEL &= ~(_GPIO_P_MODEL_MODE1_MASK);
        gpio->P[0].MODEL |= GPIO_P_MODEL_MODE1_INPUTPULLFILTER;
        gpio->P[0].DOUT |= (1 << 1);

#endif
  GPIO_PinModeSet(gpioPortA, 1, gpioModeInputPullFilter, 0); 

/*
 * Led.
 */
#if 0
        /* enable LEDs PA0*/
        gpio->P[0].MODEL &= ~(_GPIO_P_MODEL_MODE0_MASK);
        gpio->P[0].MODEL |= GPIO_P_MODEL_MODE0_PUSHPULLDRIVE;
        gpio->P[0].DOUT &= ~(1 << 0);
        
        gpio->P[0].CTRL = 0x2; // 20mA outputs

#endif

  GPIO_PinModeSet(gpioPortA, 0, gpioModePushPullDrive, 0);
  GPIO_DriveModeSet(gpioPortA, gpioDriveModeHigh);
}

int main(int argc, char **argv)
{
#if 0
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_6, (IOCON_FUNC1 | IOCON_MODE_INACT));/* RXD */
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO1_7, (IOCON_FUNC1 | IOCON_MODE_INACT));/* TXD */
#endif

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

  testStart();
  return 0;
}
