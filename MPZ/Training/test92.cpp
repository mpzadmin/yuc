#include <iostream>
#include <exception>

using namespace std;

int main()
{    
    try 
    {
        throw "Exception Handling";    
    } 
    catch(const char* e)
    {
        cout << e << endl;
    }    
}
