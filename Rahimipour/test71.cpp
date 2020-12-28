#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;
    
int main()
    
{
    int age;

    cout << "Enter your name: ";
    cin >> age;

    try
    {
        if (age >= 18)
        {
            cout << "Access to the program.";
        }
        else
        {
            throw (age); // or: throw age
        }
        
    }

    catch(int value)
    {
        cout << "Access denied."
    }
}