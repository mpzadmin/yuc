#include<iostream>
#include<string>

using namespace std;
void display(string );
void display(string , bool );

int main()
{
    display("welcome", true);
     display("Hello");
    display("bye", false);
}

void display(string str)
{
    cout<<str;
}

void display(string str, bool newLine)
{
    display(str);
    if(newLine == true)
    {
        cout<<endl;
    }
}
