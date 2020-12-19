#include <iostream>
using namespace std;
void display(string str);
void display(string str ,bool newline);
int main()
{
    display("hello",true);
    display("welcome");
    display("bye",true);
}
void display(string str)
{
    cout << str;
}
void display(string str ,bool newline)
{
    void display();
    if (newline)
    {
        cout <<endl;
    }
}