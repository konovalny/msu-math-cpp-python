CPPSOURCES := $(shell find . -name "*.cpp")
CFLAGS := -Wall -Wextra -Wfloat-equal -O  -MMD -Wstrict-prototypes  -g

LDLIBS := -lm -lpthread -lstdc++
SOFLAGS := -fPIC -shared

werror: all
all: myClass.so main.cpp
	g++ $(CFLAGS) -L./ main.cpp -lmyClass -o ./prog

myClass.so: myClass.cpp myClass.hpp
	g++ $(CFLAGS) $(SOFLAGS) $(LDLIBS) myClass.cpp -o ./libmyClass.so


clean:
	rm -f main
	rm -f *.o
	rm -f *.d
	rm -f *.so
