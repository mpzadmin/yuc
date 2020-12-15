#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5;
    int b, c, d, e, f;

    b = a++;
    cout << "a = " << a << endl;    // print 6
    cout << "b = " << b << endl;    // print 5

    c = ++a;
    cout << "a = " << a << endl;    // print 7
    cout << "c = " << c << endl;    // print 7

    d = a--;
    cout << "a = " << a << endl;    // print 6
    cout << "d = " << d << endl;    // print 7

    e = --a;
    cout << "a = " << a << endl;    // print 5
    cout << "e = " << e << endl;    // print 5

    return 0;
}
