#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;
    
int main(int argc, char const *argv[])
    
{
    if (argc <= 1) // argc default is 1.
    {
        cout << "you have to enter a name." << endl;
        return 0;
    }

        cout << "Hello" << argv[1] << endl;
    
    
    
    
    
    
    /*
    for (int index = 0; index < argc; index++)
    {
        cout << argv[index] << endl;
    }
    */
}