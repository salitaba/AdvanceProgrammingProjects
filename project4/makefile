
CC = g++ -std=c++11

main: main.o Manager.o Thread.o Core.o Cpu.o Process.o
	$(CC) -o Scheduler.out main.o Manager.o Thread.o Core.o Cpu.o Process.o

main.o: main.cpp Thread.h Core.h Cpu.h Manager.h Process.h
	$(CC) -c main.cpp

Manager.o: Manager.cpp Manager.h
	$(CC) -c Manager.cpp

Thread.o: Thread.cpp Thread.h
	$(CC) -c Thread.cpp

Core.o: Core.cpp Core.h
	$(CC) -c Core.cpp

Cpu.o: Cpu.cpp Cpu.h
	$(CC) -c Cpu.cpp

Process.o: Process.cpp Process.h
	$(CC) -c Process.cpp


.PHONY: clean
clean:
	rm *.o
	rm *.out
