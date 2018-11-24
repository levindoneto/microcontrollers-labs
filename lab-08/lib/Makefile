TARGET=libspi.a
SRCS=sclkslave.cpp mosislave.cpp ssslave.cpp

FLAGS=-O2 -Wall -g -MMD
INCLUDE=-I. -I../include
LIBDIR=
LIBS=

CC=$(CROSS_COMPILE)g++
CCAR=$(CROSS_COMPILE)ar
CFLAGS=$(FLAGS) $(INCLUDE)
LDFLAGS=$(LIBDIR) $(LIBS)
CCARFLAGS=-crvs

all: $(TARGET)

$(TARGET): $(SRCS:.cpp=.o)
	$(CCAR) $(CCARFLAGS) $@ $^ 

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

-include $(SRCS:.cpp=.d)

clean:
	rm -f *~ *.bak *.o *.d

distclean: clean
	rm -f $(TARGET)
