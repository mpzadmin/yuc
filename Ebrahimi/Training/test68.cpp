#include <iostream>

using namespace std;

int main(int argc, const char** argv)
{
    if (argc <= 1)
    {
        cout << "You have to enter a name in parameter line!" << endl;
        return 0;
    }

    cout << "Hello " << argv[1] << endl;
}
    