#include <iostream>

using namespace std;

int main (int argc, const char **argv)
{
    if (argc <= 1)
    {
        cout << "You should enter a name after file's name" << endl;
        return 0;
    }

    cout << "Hello " << argv[1] << endl;
    return 0;
}
