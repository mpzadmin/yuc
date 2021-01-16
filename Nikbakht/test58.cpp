#include<iostream>
#include<string>
using namespace std;
void display(string* str ,int len);
int main()
{
    string name = "hossein";
    string* ptr = &name;
    display(ptr , name.length());
}
void display(string* str ,int len)
{
    
    for (int index = 0 ; index < len ; index++)
    {
        cout << (*str)[index] << endl;
    }
}