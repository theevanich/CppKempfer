#
# The compiler: gcc for C program, g++ for C++
#
CC := gcc
CPP := g++
GDB = gdb
RM = rm

#
# Paths, where compiler and linker can find all the stuff
#
LDFLAGS += -L/usr/lib/x86_64-linux-gnu

INCLUDE += -I/usr/include
INCLUDE += -I/usr/local/include

#
# Compiler flags
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
CFLAGS += -g -Wall
CPPFLAGS += -std=c++11 -g -Wall
LDFLAGS += -lstdc++

#
# Source files
#
C_SRC = $(wildcard *.c)
CPP_SRC = $(wildcard *.cpp)
OBJS = $(CPP_SRC:.cpp=.o)
HEADERS = $(wildcard *.h)
TARGET := ueb06

#
# Detect operating system
#
ifeq ($(OS),Windows_NT)
    CPPFLAGS += -D WIN32
    TARGET := $(TARGET).exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CPPFLAGS += -D LINUX

        # Matthias prefers colorgcc
        CC := colorgcc
        CPP := colorgcc
    endif
    ifeq ($(UNAME_S),Darwin)
        CPPFLAGS += -D OSX
    endif
endif


#
# Build targets
#

all: $(TARGET)

run: $(TARGET)
	@./$(TARGET)

debug: $(TARGET)
	$(GDB) $^ -ex="r"

$(TARGET): Makefile $(CPP_SRC) $(HEADERS) $(OBJS)
	@rm -f $@
	$(CPP) $(LDFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	$(RM) -f $(TARGET) *.o *.elf

