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
#include "test.h"

#define LED1_PORT 3      // Port for led
#define LED2_PORT 3
#define LED3_PORT 3

#define LED1_BIT 0       // Bit on port for led
#define LED2_BIT 1       // Bit on port for led
#define LED3_BIT 2

#define LED_ON 1        // Level to set port to turn on led
#define LED_OFF 0       // Level to set port to turn off led


void testLedSet(LED_t led, bool on)
{
  switch (led) {
  case Red:
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED1_PORT, LED1_BIT, !on);
    break;

  case Green:
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED3_PORT, LED3_BIT, !on);
    break;

  case Yellow:
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED2_PORT, LED2_BIT, !on);
    break;

  }
}

static void runningLightTask(void* arg)
{
  char led = 0;

  while (1) {

    if (led == 0) {

      Chip_GPIO_SetPinState(LPC_GPIO_PORT, 3, 3, 0);
      posTaskSleep(MS(100));
      Chip_GPIO_SetPinState(LPC_GPIO_PORT, 3, 3, 1);
    }
    else {

      Chip_GPIO_SetPinState(LPC_GPIO_PORT, 2, 3 + led, 0);
      posTaskSleep(MS(100));
      Chip_GPIO_SetPinState(LPC_GPIO_PORT, 2, 3 + led, 1);

    }

    ++led;
    if (led > 4)
      led = 0;
  }
}

void testInitIO()
{
  Chip_GPIO_Init(LPC_GPIO_PORT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, LED1_PORT, LED1_BIT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, LED2_PORT, LED2_BIT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, LED3_PORT, LED3_BIT);

  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 3, 3);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 2, 4);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 2, 5);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 2, 6);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 2, 7);

  posTaskCreate(runningLightTask, NULL, 5, 400);
}

int main(int argc, char **argv)
{
#if PORTCFG_CONOUT_ITM == 1
  Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_GPIO);
  Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_IOCON);
  Chip_Clock_SetTraceClockDiv(1);
  Chip_IOCON_PinMuxSet(LPC_IOCON, IOCON_PIO0_9, IOCON_FUNC3);
#if OLD_INIT
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6); // GPIO Clock
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // IOCON Clock
  LPC_SYSCON->TRACECLKDIV = 1; // Trace clock
  LPC_IOCON->PIO0_9 = 3; // Enable SWO on PIO0.9

#endif
#endif
  testStart();
  return 0;
}

