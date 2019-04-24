#ifndef FOOD_H
#define FOOD_H
#include <iostream>

class Food {
public:
	Food(std::string _name, int _price) :name(_name), price(_price) {};

private:
	std::string name;
	int price;
};
#endif