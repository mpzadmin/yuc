#include <iostream>
#include <string>
using namespace std ;

void display(string* ptr, int length);

int main(int argc, char const *argv[])
{
    string name = "ALIREZA";
    display(&name, name.length());

    return 0;
}
void display(string* ptr, int length)
{
    for (int index = 0; index < length;index++ )
    {
        cout<< (*ptr)[index] << endl ;
    }
    
}
