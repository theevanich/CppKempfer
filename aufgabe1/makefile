# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = playground
HEADERS = tdate.h ttime.h

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).cpp tdate.cpp ttime.cpp

clean:
	$(RM) $(TARGET)