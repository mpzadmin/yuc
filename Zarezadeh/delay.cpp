#include <iostream>
#include <string>

using namespace std;

void delay(int delay = 50);

int main()
{
    string name = "Mahdi zarezadeh";
    for (int index = 0; index < name.length(); index++)
    {
        cout << name[index];
        delay();
    }
}

void delay(int delay)
{
    for (int index = 0; index < delay; index++)
    {
        for(int counter=0; counter < 5000000; counter++);
    }
}