#include <iostream>
#include <string>

using namespace std;

void delay(int);

int main()
{
    string text = "Hello world!";
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i];
        delay(20000000);
    }
}

void delay(int d)
{
    for (int i = 0; i < d; i++);
}