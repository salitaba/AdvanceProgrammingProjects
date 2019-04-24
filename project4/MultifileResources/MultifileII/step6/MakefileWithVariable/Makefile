CC = g++ --std=c++11

all: a.out

a.out: main.o Customer.o Food.o Order.o
	${CC} main.o Customer.o Food.o Order.o

main.o: main.cpp Food.h Order.h Customer.h
	${CC} -c main.cpp

Customer.o: Customer.cpp Customer.h Food.h Order.h
	${CC} -c Customer.cpp

Order.o: Order.cpp Order.h Food.h Customer.h
	${CC} -c Order.cpp

Food.o: Food.cpp Food.h
	${CC} -c Food.cpp


.PHONY: clean
clean:
	rm *.o 
	rm a.out
