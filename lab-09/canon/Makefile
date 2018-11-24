TARGET1=tx
SRCS1=$(TARGET1).c

TARGET2=rx
SRCS2=$(TARGET2).c

TARGETS=$(TARGET1) $(TARGET2)

FLAGS=-Wall -MMD -g
INCLUDE=-I.
LIBDIR=
LIBS=

CC=$(CROSS_COMPILE)gcc
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIBDIR) $(LIBS)

all: $(TARGETS)

$(TARGETS) : % : %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(SRCS:.c=.d)

clean:
	rm -f *~ *.bak *.o *.d

distclean: clean
	rm -f $(TARGETS)
