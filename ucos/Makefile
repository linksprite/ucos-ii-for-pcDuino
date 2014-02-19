
SUBDIRS = port

TARGET = $(BUILDDIR)/ucos.o
OBJS = $(BUILDDIR)/os_core.o \
       $(BUILDDIR)/os_dbg_r.o \
       $(BUILDDIR)/os_flag.o \
       $(BUILDDIR)/os_mbox.o \
       $(BUILDDIR)/os_mem.o \
       $(BUILDDIR)/os_mutex.o \
       $(BUILDDIR)/os_q.o \
       $(BUILDDIR)/os_sem.o \
       $(BUILDDIR)/os_task.o \
       $(BUILDDIR)/os_time.o \
       $(BUILDDIR)/os_tmr.o \
       $(BUILDDIR)/port.o

all: subdirs $(TARGET)

subdirs:
	@for dir in $(SUBDIRS) ; do $(MAKE) -C $$dir || exit 1; done

$(TARGET): $(OBJS)
	@$(LD) -r $^ -o $@ 
	@echo "  [LD] $@"

clean:
	find . -name "*.o" -o -name "*.exe" | xargs rm -rf  

include $(TOPDIR)/config.mk
