





#include <vector>
#include "Order.h"

class Customer {
public:
	Customer(std::string _name) :name(_name) {};

private:
	std::string name;

	std::vector<Order*> orders;
};
