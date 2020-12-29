#include <iostream>
#include <exception>

using namespace std;

int main()
{    
    try 
    {
        throw 404;    
    } 
    catch(exception &value)
    {
        cout << value.what() << endl;
    }    
}
