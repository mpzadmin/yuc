#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10, y;

    y = (x=20, x++, x-=2);
    cout << y << endl;
    y = (x=20, x++, x-5);
    cout << y << endl;

    return 0;
}
