###############################################################################
#
# Name: Makefile
#
# Description: Makefile to build ucos linux port sample code.
#
# Author: Philip Mitchell
#
###############################################################################

#objects := $(patsubst %.c,%.o,$(wildcard *.c))
#CFLAGS += -I./ -I/usr/include
#sample:$(objects)
#	cc -o sample $(objects)


TARGET = $(BUILDDIR)/port.o
OBJS := $(BUILDDIR)/os_cpu_c.o

$(TARGET):$(OBJS)
	@$(LD) -r $^ -o $@
	@echo "  [LD] $@"

include $(TOPDIR)/config.mk

