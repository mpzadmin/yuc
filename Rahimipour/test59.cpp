#include <iostream>
#include <string>

using namespace std;

void display(string str);
void display(string str, bool newLine);

int main()
{
    display("Hello", true);
    display("Welcome");
}

void display(string str)
{
    cout << str;
}

void display(string str, bool newLine)
{
    display(str); // to prevent repeating 
    if (newLine)
    {
        cout << endl;
    }
}