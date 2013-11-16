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

#include <HAL_TLV.h>

#ifdef __CC430F5137__
#define OLIMEX_CCRF
struct s_TLV_Die_Record* die;
struct s_TLV_ADC_Cal_Data * adcCal;
unsigned char tlvSize;
#endif

#ifdef __MSP430FG4619__
#define OLIMEX_4619LCD
#endif

#if defined(__MSP430G2553__) || defined(__MSP430G2533__)
#define TI_LAUNCHPAD
#endif

#ifdef __MSP430F2274__
#define TI_RF2500
#endif

#ifdef OLIMEX_CCRF

#define     LED_RED               BIT0
#define     LED_GREEN             0 // not present
#define     LED_DIR               P1DIR
#define     LED_OUT               P1OUT

#endif

#ifdef TI_RF2500

// TI ez430-RF2500

#define     LED_RED               BIT0
#define     LED_GREEN             BIT1
#define     LED_DIR               P1DIR
#define     LED_OUT               P1OUT

#endif

#ifdef TI_LAUNCHPAD

// Launchpad

#define     LED_RED               BIT0
#define     LED_GREEN             BIT6
#define     LED_DIR               P1DIR
#define     LED_OUT               P1OUT

#endif

void testLedSet(LED_t led, bool on)
{
#ifndef OLIMEX_4619LCD
  switch (led) {
  case Red:
    if (on)
      LED_OUT |= LED_RED;
    else
      LED_OUT &= ~LED_RED;

    break;

  case Green:
#if defined(TI_RF2500) || defined(TI_LAUNCHPAD)
    if (on)
      LED_OUT |= LED_GREEN;
    else
      LED_OUT &= ~LED_GREEN;

#endif
    break;

  case Yellow:
    break;
  }
#endif
}

void testInitIO()
{
#ifndef OLIMEX_4619LCD
  LED_DIR |= LED_RED;
  LED_OUT &= ~LED_RED;

#if defined(TI_RF2500) || defined(TI_LAUNCHPAD)
  LED_DIR |= LED_GREEN;
  LED_OUT &= ~LED_GREEN;
#endif
#endif

#ifdef __CC430F5137__
  Get_TLV_Info(TLV_DIERECORD, 0, &tlvSize, (unsigned int**)&die);
  if (die != NULL) {

    nosPrintf("DIe record %lu %u %u %u\n", die->wafer_id, die->die_x_position, die->die_y_position,
                                            die->test_results);
  }

  Get_TLV_Info(TLV_ADCCAL, 0, &tlvSize, (unsigned int **)&adcCal);
  if (adcCal != NULL &&
      (adcCal->adc_ref15_30_temp == adcCal->adc_ref20_30_temp ||
       adcCal->adc_ref15_30_temp == adcCal->adc_ref25_30_temp)) {

    // Calibration data wrong, see device errata datasheet
    nosPrint("This chip has calibration data error.\n");
  }

#endif
}

/*
 * Initialize board pins.
 */

static void initPins(void)
{

#if PORTCFG_XT1_HZ > 0

#if defined(__cc430x513x)

  P5OUT = 0x00;
  P5SEL |= BIT1 + BIT0;

  UCSCTL6 &= (~XTS);        // Select Low-frequency mode.
  UCSCTL6 |= XCAP_3;        // Internal load cap.

#elif defined(__msp430xG46x)

  FLL_CTL0 &= (~XTS_FLL);   // Select Low-frequency mode.
  FLL_CTL0 |= OSCCAP_3;     // Set load capacitance for xtal

#elif defined(__MSP430G2553__) || defined(__MSP430G2533__)

  // Pins default to XT1 usage on POR

#else
#error dont know which pins are connected to XT1
#endif

#endif

#if NOSCFG_FEATURE_CONOUT == 1 || NOSCFG_FEATURE_CONIN == 1

/*
 * Program * TX & RX pin for usart use.
 */

  UCA0CTL1 |= UCSWRST;

#if defined(__msp430x22x4) || defined(__msp430x22x2)

  P3DIR |= BIT4;                            // Set P3.4 as TX output
  P3SEL |= 0x30;            // P3.4,5 = USCI_A0 TXD/RXD

#elif defined(__cc430x513x)

  P1DIR |= BIT6;                            // Set P1.6 as TX output
  P1SEL |= BIT5 + BIT6;                     // Select P1.5 & P1.6 to UART function

#elif defined(__MSP430G2553__) || defined(__MSP430G2533__)

  P1DIR |= BIT2;                            // Set P1.2 as TX output
  P1SEL |= BIT1 + BIT2;                     // Select P1.1 & P1.2 to UART function
  P1SEL2 |= BIT1 + BIT2;                     // Select P1.1 & P1.2 to UART function

#elif defined(__msp430xG46x)

  P4DIR |= BIT0;                            // Set P4.0 as TX output
  P4SEL |= BIT0 + BIT1;                     // Select P4.0 & P4.1 to UART function

#else

#error missing usart tx/rx pinout

#endif
#endif

#ifdef OLIMEX_CCRF

// P3.7 = SMCLK

  P3DIR |= BIT7;
  P3SEL |= BIT7;

// P2.6 = ACLK

  P2DIR |= BIT6;
  P2SEL |= BIT6;

#endif

#ifdef OLIMEX_4619LCD

// P1.4 = SMCLK

  P1DIR |= BIT4;
  P1SEL |= BIT4;

// P1.5 = ACLK

  P1DIR |= BIT5;
  P1SEL |= BIT5;

#endif
}

int main(int argc, char **argv)
{
  initPins();
  testStart();
  return 0;
}
