#include <iostream>
#include <string>

using namespace std;

void display(string str);
void display(string str, bool newLine);


int main()
{
    display("Hello");
    display("Welcome", true);
    display("bye", true);
    return 0;
}


void display(string str)
{
    cout << str;
}

void display(string str, bool newLine)
{
    display(str);
    if (newLine)
    {
        cout << endl;
    }
}