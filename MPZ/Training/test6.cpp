#include <iostream>
#include <string>

//using std::cout;
using namespace std;

int main(int argc, char const *argv[])
{
    char myChar = '*';
    int myIntNumber = 10;
    float myFloatNumber = 3.4;
    double myDoubleNumber = 2.5;
    bool myBoolean = false;        // true = 1   or false = 0
    string myString = "Hello";    

    cout << "Char: " << sizeof(myChar);
    cout << "Int: " << sizeof(myIntNumber);
    cout << "Float: " << sizeof(myFloatNumber);
    cout << "Doubke: " << sizeof(myDoubleNumber);
    cout << "Boolean: " << sizeof(myBoolean);
    cout << "String: " << sizeof(myString);

    cout << myBoolean;
    return 0;
    
}
