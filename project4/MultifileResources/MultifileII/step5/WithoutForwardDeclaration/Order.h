



#ifndef ORDER_H
#define ORDER_H
#include <iostream>


class Order {
public:
	Order(std::string _time, int _count, Food* _food) :time(_time), count(_count), food(_food) {};

private:
	std::string time;
	int count;

	Food* food;
	Customer* owner;
};
#endif