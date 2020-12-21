#include <iostream>  

using namespace std;

int max(int a, int b);

//Finding the maxNumber between two numbers using function
int main()
{
    int number1, number2;
    cout << "Enter two numbers: ";
    cin >> number1 >> number2;

    cout << max(number1, number2) << endl;
}

int max(int a, int b)
{
    int result;
    if (a > b)
        return result = a;
    else
        return result = b;
    //Tow "return"s above lead to having an output from this function but not printing sth    
}
