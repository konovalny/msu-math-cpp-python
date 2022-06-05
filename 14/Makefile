CSOURCES := $(shell find . -name "*.c")
CFLAGS := -Wall -Wextra -Wfloat-equal -O  -MMD -Wstrict-prototypes

all: CFLAGS := $(CFLAGS) -g

LDLIBS := -lm -lpthread -lstdc++
all: LDFLAGS := -fPIC -shared
LDFLAGS := -fPIC -shared

werror: all
all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) ${CSOURCES} -o ./lib.so

clean:
	rm -f main
	rm -f *.o
	rm -f *.d
	rm -f *.so
