#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{    
    int number, key;
    
    system("cls");
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a key for encryption: ";
    cin >> key;

    number = number ^ key;
    cout << "The encrypted number is " << number << endl;
    
    number = number ^ key;
    cout << "The original number is " << number << endl;

    return 0;
}
