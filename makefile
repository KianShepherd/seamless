

TARGET = seamless
CC = g++
CFLAGS  = -g -Wall -std=c++11

all: main.o cpu.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o cpu.o

cpu.o: src/cpu.cpp include/cpu.h
	$(CC) $(CFLAGS) -c src/cpu.cpp

main.o: main.cpp src/cpu.cpp include/cpu.h
	$(CC) $(CFLAGS) -c main.cpp

clean: 
	$(RM) count *.o *~