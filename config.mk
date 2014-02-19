CC = gcc
LD = ld
DIR=$(shell pwd)/../arduino
INCS = -I.\
        -I$(DIR)/sample \
        -I$(DIR)/hardware \
        -I$(DIR)/hardware/arduino \
        -I$(DIR)/hardware/arduino/cores \
        -I$(DIR)/hardware/arduino/cores/arduino \
        -I$(DIR)/hardware/arduino/variants \
        -I$(DIR)/hardware/arduino/variants/sunxi \
        -I$(DIR)/libraries \
        -I$(DIR)/libraries/Serial \
        -I$(DIR)/libraries/SPI \
        -I$(DIR)/libraries/Wire \
        -I$(DIR)/libraries/LiquidCrystal \
        -I$(DIR)/libraries/PN532_SPI

CFLAGS = -Wall -g -I$(TOPDIR)/ -I$(TOPDIR)/ucos/ -I$(TOPDIR)/ucos/port/
LDFLAGS = -lpthread -larduino -L./arduino

$(BUILDDIR)/%.o : %.c
	@$(CC) $(CFLAGS) $(INCS) -c -o   $@ $^
	@echo "  [CC] $@"
