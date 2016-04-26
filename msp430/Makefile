#
# Copyright (c) 2012-2013, Ari Suutari <ari@stonepile.fi>.
# All rights reserved. 
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. The name of the author may not be used to endorse or promote
#     products derived from this software without specific prior written
#     permission. 
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
# INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.

RELROOT = ../../picoos/
PORT = msp430

MCU ?= msp430f2274
#MCU ?= cc430f5137
#MCU ?= msp430fg4619 
#MCU ?= msp430g2533

export MCU

BUILD ?= DEBUG

ifeq '$(MCU)' 'msp430g2533'

# too small ram, must optimize
EXTRA_CFLAGS=-Os -DSMALL_STACK
export EXTRA_CFLAGS

endif

include $(RELROOT)make/common.mak

NANO = 1
TARGET = test
SRC_TXT =	main.c ../common/test.c
SRC_HDR = 
SRC_OBJ =
SRC_LIB =
DIR_USRINC +=	../common \
		../../picoos-micro ../../picoos-micro/ports/msp430/hal5xx6xx

DIR_CONFIG = $(CURRENTDIR)
DIR_OUTPUT = $(CURRENTDIR)/bin
MODULES += ../../picoos-micro

POSTLINK1 = msp430-size $(TARGETOUT)

# ---------------------------------------------------------------------------
# BUILD THE EXECUTABLE
# ---------------------------------------------------------------------------

include $(MAKE_OUT)

