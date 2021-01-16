#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 1, sum = 0, count;

    cout << "Enter a number: ";
    cin >> count;

    for (int index=0; index<count; index++)
    {
        sum = a + b;
        cout << sum << "\t";
        a = b;
        b = sum;
    }    

}