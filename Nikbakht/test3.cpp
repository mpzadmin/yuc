#include<iostream>
#include<string>

using namespace std;

void display(string str);
void display(string str , bool test);

int main()
{
    display("hello");
    display("hi" , true);
}
void display(string str)
{
    cout << str ;

}
void display(string str , bool test)
{
    display(str);
    if (test==true)
    {
        cout << endl;
    }
}

