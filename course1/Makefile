#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
ifeq ($(PLATFORM),MSP432)

# Architectures Specific Flags
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
DUMP = arm-none-eabi-objdump
LINKER_FILE =./msp432p401r.lds
LDFLAGS = -Wl,-Map=$(TARGET).map -T$(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
# etc
else
CC = gcc
SIZE = size
DUMP = objdump
# etc
endif
#Debug Overrides
ifeq ($(VERBOSE), VERBOSE)
debug = -DVERBOSE
endif
#Program Overrides
ifeq ($(COURSE1), COURSE1)
program = -DCOURSE1
endif
#Common Flags
COFLAG = -Wall -g -O0 -std=c99
# Common Variables
TARGET = course1
PLATFORM = $(PLATFORM) 
CLEAN_O = src/main.o src/memory.o src/$(TARGET).o src/data.o src/stats.o
CLEAN_I = main.i memory.i
CLEAN_ASM = main.asm memory.asm c1m2.asm
OBJS = $(SOURCES:.c=.o)
course1 = $(PROGRAM)

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(COFLAG) $(INCLUDES) $(debug) $(program) -D$(PLATFORM) -o $@ -lm

.PHONY: build
build: $(TARGET).out
	$(SIZE) -Btd $(TARGET).out $(OBJS)

.PHONY: clean
clean:
	rm -f $(TARGET).out $(TARGET).map $(CLEAN_O) $(CLEAN_I) $(CLEAN_ASM)

.PHONY: compile-all
compile-all: $(OBJS)

%.i : %.c
	$(CC) -E $< $(INCLUDES) $(CFLAGS) $(COFLAG) $(debug) $(program) -D$(PLATFORM) -o $@ -lm

%.asm : %.c
	$(CC) -S $< $(INCLUDES) $(CFLAGS) $(COFLAG) $(debug) $(program) -D$(PLATFORM) -o $@ -lm

$(TARGET).asm : $(TARGET).out
	$(DUMP) -S -d $< > $@

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) $(COFLAG) $(LDFLAGS) $(debug) $(program) -Wall -o $@ -lm




