#include <iostream>

using namespace std;
void display(string* , int);

int main()
{
    string text = "This is a test";
    display(&text, text.length());
}

void display(string* text, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << (*text)[i] << endl;
    }
}