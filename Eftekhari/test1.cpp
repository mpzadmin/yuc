#include <iostream>
#include <string>
using namespace std ;

void delay(int delayvalue = 30);
int main(int argc, char const *argv[])
{
    string name = "ALIREZA EFTEKHARI!" ;
    for (int index = 0; index < name.length(); index++)
    {
        cout << name[index] ;
        delay( ) ;
    }
    
    return 0 ;
}

void delay(int delayvalue)
{
    for (int index = 0; index < delayvalue; index++)
    {
        for(int counter = 0; counter < 1500000; counter++);
    }
    
}

