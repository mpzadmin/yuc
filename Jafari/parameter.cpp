#include <iostream>

using namespace std;

int main(int argc, const char** argv) 
{
    if (argc <= 1)
    {
        cout << "You haven't entered any parameters.";
        return 0;
    }
    cout << "You have Entered: " << endl;
    for (int index = 1; index < argc; index++)
    {
        cout << argv[index] << endl;
    }
    return 0;
}