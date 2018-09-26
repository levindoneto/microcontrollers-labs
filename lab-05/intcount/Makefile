DEVKIT_HOME=/opt/iot-devkit/devkit-x86
PATH+=:$(DEVKIT_HOME)/sysroots/x86_64-pokysdk-linux/usr/bin/i586-poky-linux

PREFIX=
BINDIR=$(PREFIX)

TARGET=intcount
SRCS=$(TARGET).c

FLAGS=-Wall -g -MMD
INCLUDE=-I. -I../include
LIBDIR=-L../lib
LIBS=-lgalileo2

CC=i586-poky-linux-gcc
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIBDIR) $(LIBS)

all: $(TARGET)

$(TARGET): $(SRCS:.c=.o) ../lib/libgalileo2.a
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(SRCS:.c=.d)

clean:
	rm -f *~ *.bak *.o *.d

distclean: clean
	rm -f $(TARGET)
