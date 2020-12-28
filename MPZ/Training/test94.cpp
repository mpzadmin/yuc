#include <iostream>
#include <exception>

using namespace std;

double divisionByZero(int x, int y);

int main()
{    
    int x = 10, y = 0;
    double result;
    try 
    {
        result = divisionByZero(x,y);
    } 
    catch(const char* e)
    {        
        cout << e << endl;
    }    
}

double divisionByZero(int x, int y)
{
    if (y == 0)
    {
        throw "Division by zero condition";
    }
    return (x/y);
}
