#include<iostream>
#include<string>
using namespace std;
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


void display( string str,int index)
{
    
    for(int index2 =0 ; index2 < str.length(); index2++)
    {
        cout << str[index2];

    }
    
}