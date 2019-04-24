all: a.out

a.out: main.o Customer.o Food.o Order.o
	g++ main.o Customer.o Food.o Order.o

main.o: main.cpp Food.h Order.h Customer.h
	g++ -c main.cpp

Customer.o: Customer.cpp Customer.h Food.h Order.h
	g++ -c Customer.cpp

Order.o: Order.cpp Order.h Food.h Customer.h
	g++ -c Order.cpp

Food.o: Food.cpp Food.h
	g++ -c Food.cpp


.PHONY: clean
clean:
	rm *.o 
	rm a.out