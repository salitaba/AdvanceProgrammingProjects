#include "Customer.h"

void Customer::addOrder(Order* _order) {
	orders.push_back(_order);

	int a;

	_order->setOwner(this);
}