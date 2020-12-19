#include <iostream>

using namespace std;

void test(int &a, int &b);
void exchange(int &x, int &y);

int main()
{
    int a = 10;
    int b = 20;
    cout << "a = " << a << "  , b = " << b << endl;
    test(a,b);
    cout << "a = " << a << "  , b = " << b << endl;
    exchange(a,b);
    cout << "a = " << a << "  , b = " << b << endl;    
}

void test(int &a, int &b)  
{
    a++;
    b++;
}

void exchange(int &x, int &y)
{
    int z = y;
    y = x;
    x = z;
}