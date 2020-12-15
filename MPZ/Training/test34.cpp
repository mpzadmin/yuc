#include <iostream>

using namespace std;

int main()
{
    char ch;
    system("cls");
    do {        
        cout << "Enter a character: ";
        cin >> ch;
        cout << "Your character is " << ch;
        cout << endl;
    } while ((ch != 'q') && (ch != 'Q'));
}