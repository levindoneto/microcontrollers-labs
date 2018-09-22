TARGET=libeng10032.a
SRCS=print.s exit.s

FLAGS=-gstabs -n --32 -a=`echo $@ | cut -f 1 -d.`.lst
INCLUDE=
LIBDIR=
LIBS=

AS=$(CROSS_COMPILE)as
ASFLAGS=-gstabs -a=`echo $@ | cut -f 1 -d.`.lst --32 \
	-MD=`echo $@ | cut -f 1 -d.`.d
CC=$(CROSS_COMPILE)gcc
CFLAGS=-O2 -Wall -MMD $(INCLUDE) -g -m32
LDFLAGS=-m32 
AR=$(CROSS_COMPILE)ar
ARFLAGS=-crvs

all: $(TARGET)

$(TARGET): $(SRCS:.s=.o)
	${AR} ${ARFLAGS} $@ $^	

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -f *~ *.bak *.o *.d *.lst *.map .kdbgrc.*

distclean: clean
	rm -f $(TARGET)
