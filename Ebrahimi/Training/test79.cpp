#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << abs(3) << "\t" << abs(-3) << endl;
    cout << sin(0) << "\t" << sin(90) << endl;
    cout << cos(0) << "\t" << cos(90) << endl;
    cout << round(132.546) << "\t" << round(132.745) << endl;
    cout << ceil(245.43) << "\t" << floor(246.783) << endl;
    cout << sqrt(16) << "\t" << sqrt(81) << "\t" << sqrt(121) << endl;
    cout << pow(2, 3) << "\t" << pow(4, 3) << "\t" << pow(1, 100) << endl;
    cout << log(1) << endl; 
}