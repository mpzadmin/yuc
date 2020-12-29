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
        if (age >= 18)
        {
            cout << "Access to the program.";
        }
        else
        {
            throw 504;
        }
        
    }

    catch(...)
    {
        cout << "Error" << endl;
    }
    /*
    catch(out_of_range &value)
    {
        cout << value.what();
    }
    catch(overflow_error &value)
    {
        cout << value.what();
    }
    catch(exception &value)
    {
        cout << value.what();
    }
    */
}