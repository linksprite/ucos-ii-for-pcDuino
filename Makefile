
SUBDIRS = ucos app

TARGET = ucos_sample
OBJS = $(BUILDDIR)/app.o \
       $(BUILDDIR)/ucos.o 

TOPDIR := $(shell if [ "$$PWD" != "" ]; then echo $$PWD; else pwd; fi)
export TOPDIR

BUILDDIR = $(TOPDIR)/build
export BUILDDIR


all: subdirs $(TARGET)

subdirs:
	@for dir in $(SUBDIRS) ; do $(MAKE) -C $$dir || exit 1; done

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)
	@echo "  [LD] $@  $(LDFLAGS)  "


clean:
	find . -name "*.o" -o -name "*.exe" | xargs rm -rf;
	rm -rf $(TARGET)

include ./config.mk
