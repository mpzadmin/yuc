#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int password = 85663002;
    int key = 123456;

    cout << "Password is " << password << endl;

    password = password ^ key;
    cout << "Encrypted Password is " << password << endl;

    password = password ^ key;
    cout << "Password is " << password << endl;

    return 0;
}
