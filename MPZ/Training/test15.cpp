#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int number;
    string result;

    system("cls");
    cout << "Enter a number: ";
    cin >> number;

    result = (number % 2) == 0 ? "Even" : "Odd";

    cout << "The " << number << " is " << result;

    /*
    (number % 2) == 0 
        ? cout << "Even" 
        : cout << "Odd";

    (number % 2) == 0 
        ? cout << "The " << number << " is " << "Even"
        : cout << "The " << number << " is " << "Odd";
    */

    return 0;
}
