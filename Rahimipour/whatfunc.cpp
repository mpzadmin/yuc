#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;
    
int main()
    
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    try
    {
       throw "Exception Handling";
    }

    catch(exception &value)
    {
        cout << value.what() << endl;
    }
}