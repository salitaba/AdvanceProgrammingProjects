
CC = g++ -std=c++11

main: main.o
	$(CC) -o Scheduler.out main.o Manager.o Thread.o Core.o Cpu.o

main.o: main.cpp Thread.h Core.h Cpu.h Manager.h
	$(CC) -c main.cpp

Manager.o: Manager.cpp Manager.h
	$(CC) -c Manager.cpp

Thread.o: Thread.cpp Thread.h

.PHONY: clean
clean:
	rm *.o
	rm *.out
