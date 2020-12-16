#include <iostream>
#include <string>

using namespace std;

void delay(int a, string name = "Hello")
{
    for (int index = 0; index <= name.length() - 1; index ++)
    {
        for (int index2 = 1; index2 <= a; index2 ++)
        {

        }
        cout << name.at(index);
    }
}

int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;
    system ("cls");
    delay(a);
    return 0;
}