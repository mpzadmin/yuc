#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    //             0000 0000 0000 0000 0000 0000 0000 0111
    int password = 0x00000007;

    //             0000 0000 0000 0000 0000 0000 1010 1111
    int key = 0x000000AF;

    cout << "Password is " << password << endl;

    //             0000 0000 0000 0000 0000 0000 1010 1000
    password = password ^ key;
    cout << "Encrypted Password is " << password << endl;

    password = password ^ key;
    cout << "Password is " << password << endl;

    return 0;
}
