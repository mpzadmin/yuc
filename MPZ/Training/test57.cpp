#include <iostream>
#include <string>

using namespace std;

void display(string str = "Hello World!", bool newLine = false);

int main()
{
    display("Hello", true);
    display("Welcome", true);
    display("Bye");       
}

void display(string str, bool newLine)
{
    cout << str;
    if (newLine)
        cout << endl; 
}


