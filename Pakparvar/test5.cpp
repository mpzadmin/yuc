#include <iostream>
#include <string>
using namespace std;
void display(string str);
void display(string str, bool newline);
int main()
{
    display("Hello",true);
    display("Welcome",true);
    display("Bye");
}
void display(string str)
{
    cout << str;
}
void display(string str, bool newline)
{
    display(str);
    if(newline)
    {
        cout << endl;
    }
}