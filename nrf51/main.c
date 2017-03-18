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
#include <stdbool.h>
#include "test.h"
#include "nrf_gpio.h"
#include "nrf_uart.h"
#include "nrf_clock.h"

#define TXPIN 9
#define RXPIN 11

void testLedSet(LED_t led, bool on)
{
  switch (led) {
  case Green:
    nrf_gpio_pin_write(18, on);
    break;

  case Red:
    nrf_gpio_pin_write(19, on);
    break;

  case Yellow:
    nrf_gpio_pin_write(20, on);
    break;

  }
}

void testInitIO()
{
  nrf_gpio_cfg_output(18);
  nrf_gpio_cfg_output(19);
  nrf_gpio_cfg_output(20);
}

int main(int argc, char **argv)
{
// configure console pins

  nrf_gpio_cfg_output(TXPIN);
  nrf_gpio_cfg_input(RXPIN, NRF_GPIO_PIN_NOPULL);

  nrf_uart_txrx_pins_set(NRF_UART0, TXPIN, RXPIN);

// Start lf clock

  nrf_clock_lf_src_set(NRF_CLOCK_LFCLK_Xtal);
  nrf_clock_event_clear(NRF_CLOCK_EVENT_LFCLKSTARTED);

  nrf_clock_task_trigger(NRF_CLOCK_TASK_LFCLKSTART);
  while (!nrf_clock_event_check(NRF_CLOCK_EVENT_LFCLKSTARTED));
  nrf_clock_event_clear(NRF_CLOCK_EVENT_LFCLKSTARTED);

  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

  testStart();
  return 0;
}
