#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "Food.h"
#include "Customer.h"

class Customer;

class Order {
public:
	Order(std::string _time, int _count, Food* _food) :time(_time), count(_count), food(_food), status(false) {};

	void setOwner(Customer* _owner);
	void endOrder();

	std::string getString();

private:
	std::string time;
	int count;
	bool status;

	Food* food;
	Customer* owner;
};
#endif