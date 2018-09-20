TARGET=hello
SRCS=$(TARGET).cpp

FLAGS=-O2 -Wall -g -MMD
INCLUDE=-I.
LIBDIR=
LIBS=

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
