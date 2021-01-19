#include <iostream>
using namespace std;

void display(string str)
{
    cout << str;
}
void display(string str ,bool newline)
{
    display(str);
    if (newline)
    {   
        cout <<endl;
    }
}