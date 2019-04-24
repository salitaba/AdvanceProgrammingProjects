






#include <string>

class Food {
public:
	Food(std::string _name, int _price) :name(_name), price(_price) {};

private:
	std::string name;
	int price;
};