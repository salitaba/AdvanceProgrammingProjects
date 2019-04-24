



#ifndef FOOD_H
#define FOOD_H
#include <iostream>

class Food {
public:
	Food(std::string _name, int _price) :name(_name), price(_price) {};

	void print();
	bool changePrice(int _price);

	// int getPrice();
	std::string getName();

private:
	std::string name;
	int price;
};
#endif