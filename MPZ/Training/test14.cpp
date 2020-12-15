#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10, y = 20, z = 5;

    // Comparison Operators
    // >  <  >=  <=  ==  !=
    cout << (x != y) << endl;

    //       false        true       true       true 
    cout << ((x > 10) && (y < 30) || (z==5) || (!(z > x))) << endl;

    return 0;
}
