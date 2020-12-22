#include <iostream>

using namespace std;

//Derefrence
//Feel the resemblances and diffrences!
int main()
{
    //For integer
    int number = 50;
    int* ptrNumber = &number;

    int numbers[] = {1, 2, 3, 4, 5};
    int* ptrNumbers = numbers;

    //For character
    char myChar = 'M';
    char* ptrMyChar = &myChar;

    char myChars[] = {'A', 'B', 'C', 'D', 'E'};
    char* ptrMyChars = myChars;

    //For string
    string myString = "Matin";
    string* ptrMyString = &myString;

    string myStrings[] = {"Mohammad", "Matin", "Ebrahimi"};
    string* ptrMyStrings = myStrings;

    //For integer
    cout << number << "\t" << *ptrNumber << endl;
    cout << numbers[2] << "\t" << ptrNumbers[2] << "\t" << *(ptrNumbers+2) << endl;

    //For character
    cout << myChar << "\t" << *ptrMyChar << endl;
    cout << myChars[3] << "\t" << ptrMyChars[3] << "\t" << *(ptrMyChars+3) << endl;

    //For string
    cout << myString << "\t" << *ptrMyString << endl;
    cout <<  myStrings[1] << "\t" << ptrMyStrings[1] << "\t" << *(ptrMyStrings+1) << endl;
}