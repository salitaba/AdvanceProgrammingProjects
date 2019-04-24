



#include "Food.h"

void Food::print() {
	std::cout << name << " - " << price << std::endl;
}

bool Food::changePrice(int _price) {
	if (_price >= 0)
		price = _price;

	return _price >= 0;
}

std::string Food::getName(){
	return name;
}