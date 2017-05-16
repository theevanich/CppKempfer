
CPP = g++
CPPFLAGS = -g -Wall

LD = ld
LDFLAGS +=

INCLUDES="taddress.o tdate.o tlocation.o tmedium.o tperson.o ttime.o"

all: ueb03.elf

%.elf: %.o
	$(LD) $(LDFLAGS) $^ $(INCLUDES) -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $^ -o $@

clean:
	rm *.o *.elf