TARGET=spi_slave_rx
SRCS=$(TARGET).cpp

FLAGS=-O2 -Wall -MMD
INCLUDE=-I. -I../include
LIBDIR=-L../lib
LIBS=-lspi

CC=$(CROSS_COMPILE)g++
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIBDIR) $(LIBS)

all: $(TARGET)

$(TARGET): $(SRCS:.cpp=.o)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(SRCS:.cpp=.d)

clean:
	rm -f *~ *.bak *.o *.d

distclean: clean
	rm -f $(TARGET)
