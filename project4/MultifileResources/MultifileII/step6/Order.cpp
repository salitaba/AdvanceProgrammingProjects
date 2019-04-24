#include "Order.h"

void Order::setOwner(Customer* _owner) {
	owner = _owner;
}

void Order::endOrder() {
	status = true;
}

std::string Order::getString() {
	return time + " " + food->getName();
}