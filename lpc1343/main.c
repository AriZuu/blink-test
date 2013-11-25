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
#include "driver_config.h"
#include "gpio.h"
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
    GPIOSetValue(LED1_PORT, LED1_BIT, !on);
    break;

  case Green:
    GPIOSetValue(LED3_PORT, LED3_BIT, !on);
    break;

  case Yellow:
    GPIOSetValue(LED2_PORT, LED2_BIT, !on);
    break;

  }
}

static void runningLightTask(void* arg)
{
  char led = 0;

  while (1) {

    if (led == 0) {

      GPIOSetValue(3, 3, 0);
      posTaskSleep(MS(100));
      GPIOSetValue(3, 3, 1);
    }
    else {

      GPIOSetValue(2, 3 + led, 0);
      posTaskSleep(MS(100));
      GPIOSetValue(2, 3 + led, 1);

    }

    ++led;
    if (led > 4)
      led = 0;
  }
}

void testInitIO()
{
  GPIOInit();
  GPIOSetDir(LED1_PORT, LED1_BIT, 1);
  GPIOSetDir(LED2_PORT, LED2_BIT, 1);
  GPIOSetDir(LED3_PORT, LED3_BIT, 1);

  GPIOSetDir(3, 3, 1);
  GPIOSetDir(2, 4, 1);
  GPIOSetDir(2, 5, 1);
  GPIOSetDir(2, 6, 1);
  GPIOSetDir(2, 7, 1);

  posTaskCreate(runningLightTask, NULL, 5, 400);
}

int main(int argc, char **argv)
{
#if PORTCFG_CONOUT_ITM == 1
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6); // GPIO Clock
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // IOCON Clock
  LPC_SYSCON->TRACECLKDIV = 1; // Trace clock
  LPC_IOCON->PIO0_9 = 3; // Enable SWO on PIO0.9

#endif
  testStart();
  return 0;
}

