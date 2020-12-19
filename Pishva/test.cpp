#include <iostream>

using namespace std;

void display (string str);
void display (string str, bool newline);

int main()
{
    display("hello", true);
    display("welcome to c++", true);
    display("bye");

    return 0;
}

void display (string str)
{
    cout << str;
}

void display (string str, bool newline)
{
    display (str);

    if (newline)
    cout << endl;
}