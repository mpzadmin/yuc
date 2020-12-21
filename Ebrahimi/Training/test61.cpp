#include <iostream>

using namespace std;

//Refrence
int main()
{
    int number1 = 25;
    int &myNumber = number1;

    cout << number1 << "\t" << myNumber << endl;  //Printing the same number
    cout << &number1 << endl;            //Printing the address of "number1" in storage
}