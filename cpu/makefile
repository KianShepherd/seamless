

TARGET = seamless
CC = g++
CFLAGS  = -g -Wall -std=c++11
RM = del

all: main.o cpu.o tests.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o cpu.o tests.o

tests.o: src/tests.cpp include/tests.h
	$(CC) $(CFLAGS) -c src/tests.cpp

cpu.o: src/cpu.cpp include/cpu.h
	$(CC) $(CFLAGS) -c src/cpu.cpp

main.o: main.cpp src/cpu.cpp include/cpu.h
	$(CC) $(CFLAGS) -c main.cpp

clean: 
	$(RM) *.o seamless.exe