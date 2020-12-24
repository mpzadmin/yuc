#include <iostream>

using namespace std;

void calculation(int a, int b);
void exchange(int &x, int &y);

//Refrence
int main()
{
    int a = 4, b = 5;

    cout << "a = " << a << "\t" << "b = " << b << endl;
    calculation(a, b);    //Function call with value      
    cout << "a = " << a << "\t" << "b = " << b << endl;
    /* Two above couts are the same because the function in between doesn't apply changes to "a" and "b"
    unless we use refrence in definition */

    exchange(a, b);       //Function call with refrences
    cout << "a = " << a << "\t" << "b = " << b << endl;
}

void calculation(int a, int b)
{
    a += ((a * 2) - 3);
    b += ((b * 2) - 3);
}

void exchange(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}