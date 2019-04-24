





#include "Customer.h"
#include "Order.h"
#include "Food.h"
using namespace std;

int main()
{
	Food fd = Food("pizza", 13);
	Order ord = Order("10:05", 3, &fd);
	Customer cust = Customer("Hassan");

	cust.addOrder(&ord);

	fd.print();
	cout << ord.getString() << endl;

	return 0;
}