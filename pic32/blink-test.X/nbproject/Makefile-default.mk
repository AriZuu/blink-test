#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../picoos/src/pico/fbit_gen.c ../../../picoos/src/pico/picoos.c ../../../picoos/src/nano/n_bhalf.c ../../../picoos/src/nano/n_conio.c ../../../picoos/src/nano/n_core.c ../../../picoos/src/nano/n_mem.c ../../../picoos/src/nano/n_reg.c ../../../picoos-micro/diag.c ../../../picoos-micro/u_init.c ../../../picoos/ports/pic32/arch_c.c ../../../picoos/ports/pic32/con_uart.c ../../../picoos/ports/pic32/tick_core.c ../../../picoos/ports/pic32/tick_timer.c ../../common/test.c ../main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/518228807/fbit_gen.o ${OBJECTDIR}/_ext/518228807/picoos.o ${OBJECTDIR}/_ext/518161878/n_bhalf.o ${OBJECTDIR}/_ext/518161878/n_conio.o ${OBJECTDIR}/_ext/518161878/n_core.o ${OBJECTDIR}/_ext/518161878/n_mem.o ${OBJECTDIR}/_ext/518161878/n_reg.o ${OBJECTDIR}/_ext/1219146993/diag.o ${OBJECTDIR}/_ext/1219146993/u_init.o ${OBJECTDIR}/_ext/500852747/arch_c.o ${OBJECTDIR}/_ext/500852747/con_uart.o ${OBJECTDIR}/_ext/500852747/tick_core.o ${OBJECTDIR}/_ext/500852747/tick_timer.o ${OBJECTDIR}/_ext/1329223797/test.o ${OBJECTDIR}/_ext/1472/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/518228807/fbit_gen.o.d ${OBJECTDIR}/_ext/518228807/picoos.o.d ${OBJECTDIR}/_ext/518161878/n_bhalf.o.d ${OBJECTDIR}/_ext/518161878/n_conio.o.d ${OBJECTDIR}/_ext/518161878/n_core.o.d ${OBJECTDIR}/_ext/518161878/n_mem.o.d ${OBJECTDIR}/_ext/518161878/n_reg.o.d ${OBJECTDIR}/_ext/1219146993/diag.o.d ${OBJECTDIR}/_ext/1219146993/u_init.o.d ${OBJECTDIR}/_ext/500852747/arch_c.o.d ${OBJECTDIR}/_ext/500852747/con_uart.o.d ${OBJECTDIR}/_ext/500852747/tick_core.o.d ${OBJECTDIR}/_ext/500852747/tick_timer.o.d ${OBJECTDIR}/_ext/1329223797/test.o.d ${OBJECTDIR}/_ext/1472/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/518228807/fbit_gen.o ${OBJECTDIR}/_ext/518228807/picoos.o ${OBJECTDIR}/_ext/518161878/n_bhalf.o ${OBJECTDIR}/_ext/518161878/n_conio.o ${OBJECTDIR}/_ext/518161878/n_core.o ${OBJECTDIR}/_ext/518161878/n_mem.o ${OBJECTDIR}/_ext/518161878/n_reg.o ${OBJECTDIR}/_ext/1219146993/diag.o ${OBJECTDIR}/_ext/1219146993/u_init.o ${OBJECTDIR}/_ext/500852747/arch_c.o ${OBJECTDIR}/_ext/500852747/con_uart.o ${OBJECTDIR}/_ext/500852747/tick_core.o ${OBJECTDIR}/_ext/500852747/tick_timer.o ${OBJECTDIR}/_ext/1329223797/test.o ${OBJECTDIR}/_ext/1472/main.o

# Source Files
SOURCEFILES=../../../picoos/src/pico/fbit_gen.c ../../../picoos/src/pico/picoos.c ../../../picoos/src/nano/n_bhalf.c ../../../picoos/src/nano/n_conio.c ../../../picoos/src/nano/n_core.c ../../../picoos/src/nano/n_mem.c ../../../picoos/src/nano/n_reg.c ../../../picoos-micro/diag.c ../../../picoos-micro/u_init.c ../../../picoos/ports/pic32/arch_c.c ../../../picoos/ports/pic32/con_uart.c ../../../picoos/ports/pic32/tick_core.c ../../../picoos/ports/pic32/tick_timer.c ../../common/test.c ../main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/518228807/fbit_gen.o: ../../../picoos/src/pico/fbit_gen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518228807" 
	@${RM} ${OBJECTDIR}/_ext/518228807/fbit_gen.o.d 
	@${RM} ${OBJECTDIR}/_ext/518228807/fbit_gen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518228807/fbit_gen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518228807/fbit_gen.o.d" -o ${OBJECTDIR}/_ext/518228807/fbit_gen.o ../../../picoos/src/pico/fbit_gen.c   
	
${OBJECTDIR}/_ext/518228807/picoos.o: ../../../picoos/src/pico/picoos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518228807" 
	@${RM} ${OBJECTDIR}/_ext/518228807/picoos.o.d 
	@${RM} ${OBJECTDIR}/_ext/518228807/picoos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518228807/picoos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518228807/picoos.o.d" -o ${OBJECTDIR}/_ext/518228807/picoos.o ../../../picoos/src/pico/picoos.c   
	
${OBJECTDIR}/_ext/518161878/n_bhalf.o: ../../../picoos/src/nano/n_bhalf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_bhalf.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_bhalf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_bhalf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_bhalf.o.d" -o ${OBJECTDIR}/_ext/518161878/n_bhalf.o ../../../picoos/src/nano/n_bhalf.c   
	
${OBJECTDIR}/_ext/518161878/n_conio.o: ../../../picoos/src/nano/n_conio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_conio.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_conio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_conio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_conio.o.d" -o ${OBJECTDIR}/_ext/518161878/n_conio.o ../../../picoos/src/nano/n_conio.c   
	
${OBJECTDIR}/_ext/518161878/n_core.o: ../../../picoos/src/nano/n_core.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_core.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_core.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_core.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_core.o.d" -o ${OBJECTDIR}/_ext/518161878/n_core.o ../../../picoos/src/nano/n_core.c   
	
${OBJECTDIR}/_ext/518161878/n_mem.o: ../../../picoos/src/nano/n_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_mem.o.d" -o ${OBJECTDIR}/_ext/518161878/n_mem.o ../../../picoos/src/nano/n_mem.c   
	
${OBJECTDIR}/_ext/518161878/n_reg.o: ../../../picoos/src/nano/n_reg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_reg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_reg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_reg.o.d" -o ${OBJECTDIR}/_ext/518161878/n_reg.o ../../../picoos/src/nano/n_reg.c   
	
${OBJECTDIR}/_ext/1219146993/diag.o: ../../../picoos-micro/diag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1219146993" 
	@${RM} ${OBJECTDIR}/_ext/1219146993/diag.o.d 
	@${RM} ${OBJECTDIR}/_ext/1219146993/diag.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1219146993/diag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1219146993/diag.o.d" -o ${OBJECTDIR}/_ext/1219146993/diag.o ../../../picoos-micro/diag.c   
	
${OBJECTDIR}/_ext/1219146993/u_init.o: ../../../picoos-micro/u_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1219146993" 
	@${RM} ${OBJECTDIR}/_ext/1219146993/u_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1219146993/u_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1219146993/u_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1219146993/u_init.o.d" -o ${OBJECTDIR}/_ext/1219146993/u_init.o ../../../picoos-micro/u_init.c   
	
${OBJECTDIR}/_ext/500852747/arch_c.o: ../../../picoos/ports/pic32/arch_c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/arch_c.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/arch_c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/arch_c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/arch_c.o.d" -o ${OBJECTDIR}/_ext/500852747/arch_c.o ../../../picoos/ports/pic32/arch_c.c   
	
${OBJECTDIR}/_ext/500852747/con_uart.o: ../../../picoos/ports/pic32/con_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/con_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/con_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/con_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/con_uart.o.d" -o ${OBJECTDIR}/_ext/500852747/con_uart.o ../../../picoos/ports/pic32/con_uart.c   
	
${OBJECTDIR}/_ext/500852747/tick_core.o: ../../../picoos/ports/pic32/tick_core.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_core.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_core.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/tick_core.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/tick_core.o.d" -o ${OBJECTDIR}/_ext/500852747/tick_core.o ../../../picoos/ports/pic32/tick_core.c   
	
${OBJECTDIR}/_ext/500852747/tick_timer.o: ../../../picoos/ports/pic32/tick_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/tick_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/tick_timer.o.d" -o ${OBJECTDIR}/_ext/500852747/tick_timer.o ../../../picoos/ports/pic32/tick_timer.c   
	
${OBJECTDIR}/_ext/1329223797/test.o: ../../common/test.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329223797" 
	@${RM} ${OBJECTDIR}/_ext/1329223797/test.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329223797/test.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329223797/test.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1329223797/test.o.d" -o ${OBJECTDIR}/_ext/1329223797/test.o ../../common/test.c   
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c   
	
else
${OBJECTDIR}/_ext/518228807/fbit_gen.o: ../../../picoos/src/pico/fbit_gen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518228807" 
	@${RM} ${OBJECTDIR}/_ext/518228807/fbit_gen.o.d 
	@${RM} ${OBJECTDIR}/_ext/518228807/fbit_gen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518228807/fbit_gen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518228807/fbit_gen.o.d" -o ${OBJECTDIR}/_ext/518228807/fbit_gen.o ../../../picoos/src/pico/fbit_gen.c   
	
${OBJECTDIR}/_ext/518228807/picoos.o: ../../../picoos/src/pico/picoos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518228807" 
	@${RM} ${OBJECTDIR}/_ext/518228807/picoos.o.d 
	@${RM} ${OBJECTDIR}/_ext/518228807/picoos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518228807/picoos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518228807/picoos.o.d" -o ${OBJECTDIR}/_ext/518228807/picoos.o ../../../picoos/src/pico/picoos.c   
	
${OBJECTDIR}/_ext/518161878/n_bhalf.o: ../../../picoos/src/nano/n_bhalf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_bhalf.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_bhalf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_bhalf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_bhalf.o.d" -o ${OBJECTDIR}/_ext/518161878/n_bhalf.o ../../../picoos/src/nano/n_bhalf.c   
	
${OBJECTDIR}/_ext/518161878/n_conio.o: ../../../picoos/src/nano/n_conio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_conio.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_conio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_conio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_conio.o.d" -o ${OBJECTDIR}/_ext/518161878/n_conio.o ../../../picoos/src/nano/n_conio.c   
	
${OBJECTDIR}/_ext/518161878/n_core.o: ../../../picoos/src/nano/n_core.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_core.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_core.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_core.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_core.o.d" -o ${OBJECTDIR}/_ext/518161878/n_core.o ../../../picoos/src/nano/n_core.c   
	
${OBJECTDIR}/_ext/518161878/n_mem.o: ../../../picoos/src/nano/n_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_mem.o.d" -o ${OBJECTDIR}/_ext/518161878/n_mem.o ../../../picoos/src/nano/n_mem.c   
	
${OBJECTDIR}/_ext/518161878/n_reg.o: ../../../picoos/src/nano/n_reg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/518161878" 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/518161878/n_reg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/518161878/n_reg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/518161878/n_reg.o.d" -o ${OBJECTDIR}/_ext/518161878/n_reg.o ../../../picoos/src/nano/n_reg.c   
	
${OBJECTDIR}/_ext/1219146993/diag.o: ../../../picoos-micro/diag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1219146993" 
	@${RM} ${OBJECTDIR}/_ext/1219146993/diag.o.d 
	@${RM} ${OBJECTDIR}/_ext/1219146993/diag.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1219146993/diag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1219146993/diag.o.d" -o ${OBJECTDIR}/_ext/1219146993/diag.o ../../../picoos-micro/diag.c   
	
${OBJECTDIR}/_ext/1219146993/u_init.o: ../../../picoos-micro/u_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1219146993" 
	@${RM} ${OBJECTDIR}/_ext/1219146993/u_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1219146993/u_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1219146993/u_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1219146993/u_init.o.d" -o ${OBJECTDIR}/_ext/1219146993/u_init.o ../../../picoos-micro/u_init.c   
	
${OBJECTDIR}/_ext/500852747/arch_c.o: ../../../picoos/ports/pic32/arch_c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/arch_c.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/arch_c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/arch_c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/arch_c.o.d" -o ${OBJECTDIR}/_ext/500852747/arch_c.o ../../../picoos/ports/pic32/arch_c.c   
	
${OBJECTDIR}/_ext/500852747/con_uart.o: ../../../picoos/ports/pic32/con_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/con_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/con_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/con_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/con_uart.o.d" -o ${OBJECTDIR}/_ext/500852747/con_uart.o ../../../picoos/ports/pic32/con_uart.c   
	
${OBJECTDIR}/_ext/500852747/tick_core.o: ../../../picoos/ports/pic32/tick_core.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_core.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_core.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/tick_core.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/tick_core.o.d" -o ${OBJECTDIR}/_ext/500852747/tick_core.o ../../../picoos/ports/pic32/tick_core.c   
	
${OBJECTDIR}/_ext/500852747/tick_timer.o: ../../../picoos/ports/pic32/tick_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/500852747" 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/500852747/tick_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/500852747/tick_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/500852747/tick_timer.o.d" -o ${OBJECTDIR}/_ext/500852747/tick_timer.o ../../../picoos/ports/pic32/tick_timer.c   
	
${OBJECTDIR}/_ext/1329223797/test.o: ../../common/test.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1329223797" 
	@${RM} ${OBJECTDIR}/_ext/1329223797/test.o.d 
	@${RM} ${OBJECTDIR}/_ext/1329223797/test.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1329223797/test.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1329223797/test.o.d" -o ${OBJECTDIR}/_ext/1329223797/test.o ../../common/test.c   
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_DBG -DPOSNANO -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../" -I"../../common" -I"../../../picoos/ports/pic32" -I"../../../picoos/inc" -I"../../../picoos-micro" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=25000,--defsym=_min_stack_size=1500,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=25000,--defsym=_min_stack_size=1500,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/blink-test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
