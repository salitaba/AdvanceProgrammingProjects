






#include "Food.h"
#include "Customer.h"s
class Order {
public:
	Order(std::string _time, int _count, Food* _food) :time(_time), count(_count), food(_food) {};

private:
	std::string time;
	int count;

	Food* food;
	Customer* owner;
};