# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = ueb03
HEADERS = tdate.h ttime.h tlocation.h taddress.h tperson.h tmedium.h tlibrary.h

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET).exe $(TARGET).cpp tdate.cpp ttime.cpp tlocation.cpp taddress.cpp tperson.cpp tmedium.cpp tlibrary.cpp

clean:
	$(RM) $(TARGET).exe