#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char myChar = 'X';
    int myIntNumber = 10;
    float myFloatNumber = 3.4;
    double myDoubleNumber = 4.6;


    // Clear screen
    system("cls");

    cout << "myChar size: " << sizeof(myChar) << " byte(s)" << endl;
    cout << "myIntNumber size: " << sizeof(myIntNumber) << " byte(s)" << endl;
    cout << "myFloatNumber size: " << sizeof(myFloatNumber) << " byte(s)" << endl;
    cout << "myDoubleNumber size: " << sizeof(myDoubleNumber) << " byte(s)" << endl;
    cout << myChar << endl;
    cout << myIntNumber << endl;
    cout << myFloatNumber << endl;
    cout << myDoubleNumber << endl;

    return 0;
}
