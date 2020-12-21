#include<iostream>
#include<string> 
#include<iomanip>
#include<conio.h>
using namespace std;

void delay(int index);
int main()
{
    string str;
    cout << "enter your name:";
    getline(cin , str);
    for( int index3 = 0 ; index3 < str.length() ; index3++)
    {
        cout << str[index3];
        delay(20000000);
        cout <<endl;
    }

}
void delay(int index)
{
    
    for(int index2 =0 ; index2 < index ; index2++)
    {

    }
    
}