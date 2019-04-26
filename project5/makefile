
CC = g++ -std=c++11
FLAG = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
main: main.o Screen.o Map.o Cell.o Object.o Background.o Flag.o Pipe.o Mario.o GameManager.o Kopa.o Block.o rsdl.o ObjectCode.o Move.o Crash.o Line.o Accident.o
	$(CC) -o game main.o Screen.o Map.o Cell.o Object.o Background.o Flag.o Pipe.o Mario.o GameManager.o Kopa.o Block.o rsdl.o ObjectCode.o Move.o Crash.o Line.o Accident.o $(FLAG)

main.o: main.cpp Screen.o Map.o Cell.o Object.o Background.o Flag.o Pipe.o Mario.o GameManager.o Kopa.o Block.o rsdl.o ObjectCode.o
	$(CC) -c main.cpp

rsdl.o: RSDL/src/rsdl.cpp
	$(CC) -c RSDL/src/rsdl.cpp 

Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp

Mario.o: Mario.cpp Mario.h
	$(CC) -c Mario.cpp

Background.o: Background.cpp Background.h
	$(CC) -c Background.cpp

Block.o: Block.cpp Block.h
	$(CC) -c Block.cpp

Kopa.o: Kopa.cpp Kopa.h
	$(CC) -c Kopa.cpp

Pipe.o: Pipe.cpp Pipe.h
	$(CC) -c Pipe.cpp

Flag.o: Flag.cpp Flag.h
	$(CC) -c Flag.cpp

Object.o: Object.cpp Object.h
	$(CC) -c Object.cpp

Map.o: Map.cpp Map.h
	$(CC) -c Map.cpp

Cell.o: Cell.cpp Cell.h
	$(CC) -c Cell.cpp

GameManager.o: GameManager.cpp GameManager.h
	$(CC) -c GameManager.cpp 	

ObjectCode.o: ObjectCode.cpp Object.h
	$(CC) -c ObjectCode.cpp

Move.o: Move.cpp Move.h
	$(CC) -c Move.cpp

Crash.o: Crash.cpp Crash.h
	$(CC) -c Crash.cpp

Line.o: Line.cpp Line.h
	$(CC) -c Line.cpp

Accident.o: Accident.cpp Accident.h
	$(CC) -c Accident.cpp
.PHONY: clean
clean:
	rm *.o
	rm *.out
