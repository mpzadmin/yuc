#include <iostream>

using namespace std;

void delay (int);

int main(int argc, char const *argv[])
{
    string str = "Hello world!";
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
        delay(3);
    }
    return 0;    
}

void delay (int delayValue)
{
    for (int i = 0; i < delayValue * 5000000; i++);
}