
TARGET = $(BUILDDIR)/app.o
OBJS := $(BUILDDIR)/sample.o

$(TARGET):$(OBJS)
	@$(LD) -r $^ -o $@
	@echo "  [LD] $@"

include $(TOPDIR)/config.mk

