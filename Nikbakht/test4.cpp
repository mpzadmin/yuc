#include<iostream>
#include<string>

using namespace std;
void display(string str , int size);
int main()
{
    string name = "hosssein";
    display( name , 7 );
}
void display(string str , int size  )
{
    string* ptr = &str;
    
    for(int index = 0 ;index < size ; index++)
    {
        cout << (*ptr)[index] << endl;
    }
}