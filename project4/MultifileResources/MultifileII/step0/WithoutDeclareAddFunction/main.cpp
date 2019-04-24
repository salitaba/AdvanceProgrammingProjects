
#include <iostream>


int add(int a, int b) {
	std::cout << "int, int" << std::endl;
	return a+b;
}

int main(int argc, char const *argv[])
{
	float a = 3.2;
	std::cout << add(2,a) << std::endl;
	return 0;
}
