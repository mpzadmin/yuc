#include <iostream>
#include <exception>

using namespace std;

int main()
{    
    try 
    {
        throw 505;    
    } 
    catch(...)
    {
        cout << "Error" << endl;
    }
}
