#include <iostream>
#include <string>

using namespace std;

void delay(int delayValue = 200000000);

int main()
{
    string line = "helloWorld";

    for (int index = 0; index <= line.length(); index++)
    {
        cout << line[index];
        delay();
    }

}

void delay(int delayValue)
{
    for(int index = 0; index <= delayValue; index++);
}