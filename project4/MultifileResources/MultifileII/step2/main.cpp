#include <vector>
#include <iostream>
using namespace std;

// class Customer;

class Food {
public:
	Food(string _name, int _price) :name(_name), price(_price) {};

private:
	string name;
	int price;
};

class Order {
public:
	Order(string _time, int _count, Food _food) :time(_time), count(_count), food(_food) {};

private:
	string time;
	int count;

	Food food;
	Customer owner;
};

class Customer {
public:
	Customer(string _name) :name(_name) {};

private:
	string name;

	vector<Order*> orders;
};


int main()
{
	/* code */
	return 0;
}