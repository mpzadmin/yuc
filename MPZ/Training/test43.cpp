#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int number = 100;
    string strNumber = "500";
    string strHexNumber = "0xFF";

    cout << "Number is " + to_string(number) << endl; 

    number = stoi(strNumber);           // stof, stol, stod
    number++;
    cout << number << endl;

    number = stoi(strHexNumber, nullptr, 16);
    number++;
    cout << number << endl;
}