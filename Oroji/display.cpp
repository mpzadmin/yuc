#include <iostream>
#include <string>
using namespace std;
void display(string* ptr,size_t len);
int main()
{
    string name = "Dani";
    display(&name , name.length());
}
void display(string* ptr,size_t len)
{
    
   for(int i=0; i<len ;i++)
    cout << (*ptr)[i] << endl;
}