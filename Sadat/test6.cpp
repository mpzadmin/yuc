#include <iostream>
#include <exception>

using namespace std;

int main()
{
    int number;
    cin >> number;
    try
    {
        //cout << 1/number;
        throw 5;
    }
    catch(...)
    {
        cout << "error";
    }
    
}