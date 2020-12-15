#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 11;    // 352 Octal          1FC0  Hex     011100 Binary
    int b = 0352;   // Octal
    int c = 0x1FC0; // Hex

    cout << a << endl;
    cout << oct << a << endl;
    cout << hex << a << endl;
    
    return 0;
}
