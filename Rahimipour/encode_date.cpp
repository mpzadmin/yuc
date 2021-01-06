// Developer: Ahad Rahimipour

/* 
We want to encode a text with the Birthdate of that person.
also use that text. the letter[0] will xor with letter[n], letter[1] xor with letter[n-1]....
Notice that if you sum the number of the letters, you will get n. 
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
    
using namespace std;

void encode(string sth, int birthDate);
void setColor(int number);

int main()
    
{
    string sth;
    int birthDate;

    system("cls");

    cout << "please enter something: ";
    getline(cin, sth);
    cout << "Enter your birthDate: ";
    cin >> birthDate;

    encode(sth, birthDate);
}

void encode(string sth, int birthDate)
{
    for (int index = 0; index < sth.length(); index++)
    {
        sth[index] = sth[index] ^ sth[(sth.length() - (index + 1))];
    }

    for (int index = 0; index < sth.length(); index++)
    {
        sth[index] = sth[index] ^ birthDate;
    }
    setColor(4);
    cout << "The encode text is: " << sth << endl;
    
    // Recovering the text: 

    for (int index = 0; index < sth.length(); index++)
    {
        sth[index] = sth[index] ^ birthDate;
    }

    for (int index = sth.length() - 1; index >= 0; index--)
    {
        sth[index] = sth[index] ^ sth[(sth.length() - (index + 1))];
    }
    system("pause");

    setColor(1);
    cout << "The original text is: " << sth << endl;
}

void setColor(int number)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, number);
}