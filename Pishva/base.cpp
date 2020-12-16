#include <iostream>

using namespace std;

void delay(int delayValue);

int main()
{
    string name;

    cout << "Print your name : ";
    getline(cin, name);

    for (int index = 0; index <= name.size() - 1; index++)
    {
        cout << name[index];
        delay(5000000);
    }

}

void delay(int delayValue)
{
    for (int index = 0; index <= delayValue; index++);
}