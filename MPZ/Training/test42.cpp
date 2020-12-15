#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int number = 100;
    bool showLoading = true;
    system("cls");
    cout << showLoading << endl;
    cout << boolalpha << showLoading << endl;

    cout << setw(20) << number << endl;
    cout << setfill('*');
    cout << setw(20) << number << endl;
    cout << setfill(' ');
    cout << setw(20) << number << endl;
    cout << setfill('-') << setw(20) << number << endl;
    cout << setw(20) << number << endl;
    cout << setfill(' ');
    cout << setw(20) << number << endl;
}