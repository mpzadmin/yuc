#include <iostream>
#include <string>

using namespace std;

void display(string str = "Hello World!", bool newLine = false)
{
    cout << str;
    if (newLine)
        cout << endl; 
}

int main()
{
    display("Hello", true);
    display("Welcome", true);
    display("Bye");       
}


