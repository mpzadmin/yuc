#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    //           0000 0000 0000 0000 0000 0000 0000 1010    
    int number = 0x0000000A;    
    cout << "Number is: "<< hex << number << endl;

    //           0000 0000 0000 0000 0000 0000 0000 1010    
    //           0000 0000 0000 0000 0000 0000 0000 0100    
    // number = number | 0x00000004;    
    number = number | 4;
    cout << "New Number is: "<< hex << number << endl;
    
    return 0;
}
