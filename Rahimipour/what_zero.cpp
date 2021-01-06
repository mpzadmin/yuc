#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;

double divisionByzero(int x, int y);

int main()
    
{
    int x = 15, y = 0;
    double result;
    try
    {
        result = divisionByzero(x,y);
    }

    catch(const char* ex)
    {
        cout << ex << endl;
    }
}

double divisionByzero(int x, int y)
{
    if (y == 0)
    {
        throw "Division by zero";
    }
    return (x/y);
}