#include <iostream>

using namespace std;

int main()
{
    int number;
    int mask = 0;
    cout << "Enter a number: ";
    cin >> number;

    // 00000000 00000000 00000000 00000000
    // 00000000 00000000 00010000 10110000      4272    0x000010B0      
    mask = 0x000010B0;  // or 0x10B0
    number = number | mask;

    // 11111111 11111111 11111111 11111111  
    // 11111111 11111111 11111101 11111011      0xFFFFFDFB 
    mask = 0xFFFFFDFB;
    number = number & mask;

    cout << "The final number is: " << number;  

    // 00000000 00000000 00000000 00000000      number 0
    // 00000000 00000000 00010000 10110000      mask   0x000010B0
    // 00000000 00000000 00010000 10110000      4272
    // 11111111 11111111 11111101 11111011      0xFFFFFDFB 
    // 00000000 00000000 00010000 10110000      4272
}