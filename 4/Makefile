CPPSOURCES := $(shell find . -name "*.cpp")
CFLAGS := -Wall -Wextra -Wfloat-equal -O  -MMD -Wstrict-prototypes

CXXFLAGS := $(CFLAGS) -std=c++17

LDLIBS := -lm -lpthread -lstdc++
all: LDFLAGS := -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all

werror: all
all: main

main: $(CSOURCES:%.c=%.o) $(CPPSOURCES:%.cpp=%.o)

DEPS := $(shell find -name "*.d")
-include $(DEPS)

clean:
	rm -f main
	rm -f *.o
	rm -f *.d
