/*
 * Copyright (c) 2012-2013, Ari Suutari <ari@stonepile.fi>.
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
#include <picoos-u.h>
#include <stdbool.h>

#include "test.h"
#include "testcfg.h"

static POSSEMA_t sema;

static void task3(void *arg)
{
  int x = 1;
  int xp = 0;
  char i;

#if NOSCFG_FEATURE_CONOUT == 1 && !defined(SMALL_STACK)
  nosPrint("task3 start\n");
#endif

  testLedSet(Red, false);

  while (true) {

    posSemaGet(sema);

    for (i = 0; i < 3; i++) {

      testLedSet(Red, true);
      posTaskSleep(MS(200));
      testLedSet(Red, false);
      posTaskSleep(MS(100));

      P_ASSERT("local var", xp + 1 == x);

      xp = x;
      ++x;
      if (x >= 1000) {

        xp = 0;
        x = 1;
      }
    }
  }
}

static void task2(void *arg)
{
  int x = 1;
  int xp = 0;

#if NOSCFG_FEATURE_CONOUT == 1 && !defined(SMALL_STACK)
  nosPrint("task2 start\n");
#endif

  while (true) {

    testLedSet(Yellow, false);
    posTaskSleep(MS(1000));

#if NOSCFG_FEATURE_CONOUT == 1 && !defined(SMALL_STACK)
    nosPrintf("task2 %d\n", x);
#endif

    testLedSet(Yellow, true);
    posTaskSleep(MS(1000));

    P_ASSERT("local var", xp + 1 == x);

    xp = x;
    ++x;
    if (x >= 1000) {

      xp = 0;
      x = 1;
    }

  }
}

static void task1(void *arg)
{
  int x = 1;
  int xp = 0;
  JIF_t spinUntil;
  POSTASK_t task;

  uosBootDiag();
  uosResourceDiag();

#if NOSCFG_FEATURE_CONOUT == 1
  nosPrint("task1 start\n");
#endif

#if POSCFG_MAX_TASKS >= 3
  sema = posSemaCreate(0);
#endif

  testInitIO();

  task = posTaskCreate(task2, NULL, POSCFG_MAX_PRIO_LEVEL - 2, TEST_STACK_SIZE);
  POS_SETTASKNAME(task, "task2");

  task = posTaskCreate(task3, NULL, POSCFG_MAX_PRIO_LEVEL - 1, TEST_STACK_SIZE);
  POS_SETTASKNAME(task, "task3");

  while (true) {

    testLedSet(Green, false);
    uosResourceDiag();
    posTaskSleep(MS(5000));

#if NOSCFG_FEATURE_CONOUT == 1
    nosPrintf("task1 %d\n", x);
#endif

    testLedSet(Green, true);
#if POSCFG_MAX_TASKS >= 3
    posSemaSignal(sema);
#endif
    spinUntil = jiffies + MS(5000);
    while (!POS_TIMEAFTER(jiffies, spinUntil));

    P_ASSERT("local var", xp + 1 == x);

    xp = x;
    ++x;
    if (x >= 1000) {

      xp = 0;
      x = 1;
    }
  }
}

void testStart()
{
  nosInit(task1, NULL, 1, MAIN_STACK_SIZE, IDLE_STACK_SIZE);
}
