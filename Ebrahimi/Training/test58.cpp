#include <iostream>

using namespace std;

bool isEven(int a);

//Is the number even?
int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << boolalpha << isEven(number) << endl;
}

bool isEven(int a)
{
    bool result;
    if ((a % 2) == 0)
        return result = true;
    else
        return result = false;     
}