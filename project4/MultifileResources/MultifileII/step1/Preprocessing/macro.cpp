#include <iostream>

#define M 10 

using namespace std;

int main()
{
    #ifdef M
        cout << "M defined" << endl;
    #endif

    #ifndef M
        cout << "M is not defined" << endl;
    #endif

}