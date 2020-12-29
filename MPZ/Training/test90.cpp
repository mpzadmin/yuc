#include <iostream>
#include <exception>

using namespace std;

int main()
{    
    try 
    {
        throw;    
    } 
    catch(out_of_range &value)
    {
        cout << value.what() << endl;
    }
    catch(overflow_error &value)
    {
        cout << value.what() << endl;
    }
    catch(exception &value)
    {
        cout << value.what() << endl;
    }
}
