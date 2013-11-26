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

#define LED1_PORT 0      // Port for led
#define LED2_PORT 0

#define LED1_BIT 2       // Bit on port for led
#define LED2_BIT 3       // Bit on port for led
#define LED_ON 1        // Level to set port to turn on led
#define LED_OFF 0       // Level to set port to turn off led

void testLedSet(LED_t led, bool on)
{
  switch (led)
  {
  case Red:
    break;

  case Green:
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED2_PORT, LED1_BIT, on);
    break;

  case Yellow:
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED1_PORT, LED2_BIT, on);
    break;

  }
}

void testInitIO()
{
  Chip_SWM_DisableFixedPin(SWM_FIXED_SWCLK);
  Chip_SWM_DisableFixedPin(SWM_FIXED_SWDIO);

  Chip_GPIO_Init(LPC_GPIO_PORT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, LED1_PORT, LED1_BIT);
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, LED2_PORT, LED2_BIT);
}

int main(int argc, char **argv)
{
  testStart();
  return 0;
}
