#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char myChar = 'X';
    int number1 = 10, number2 = 100, number3 = 200;
    int number4, number5, number6;
    

    number4 = number5 = number6 = 1000;     
    
    // Clear screen
    system("cls");

    cout << "myChar size: " << sizeof(myChar) << " byte(s)" << endl;
    cout << "number1 size: " << sizeof(number1) << " byte(s)" << endl;
    cout << number1 << "\t" << number2 << "\t" << number3 << endl;
    cout << number4 << "\t" << number5 << "\t" << number6 << endl;

    return 0;
}
