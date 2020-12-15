#include <iostream>

using namespace std;

const int maxList = 100;

int main()
{
    int list[maxList];
    int count = 0;
    char action;
    int result;    

    system("cls");
    cout << "Enter count of numbers: ";
    cin >> count;

    if (count > maxList)
    {
        cout << "You should enter a number less than 100";
        return 0;
    } 

    for (int index = 0; index < count; index++)
    {
        cout << "Enter number [" << (index+1) << "]: ";
        cin >> list[index];
    }

    cout << endl << "Enter a character for action (+ or *): ";
    cin >> action;

    if ( (action != '+') && (action != '*') )
    {
        cout << "You entered a wrong action character!";
        return 0;
    }

    (action == '+') ? result = 0 : result = 1;
    for (int index = 0; index < count; index++)
    {
        (action == '+') ? result += list[index] : result *= list[index];

        /*
        if (action == '+')
        {
            result += list[index];
        } 
        else
        {
            result *= list[index];
        }
        */

        
        /*
        switch (action)
        {
        case '+':
            result += list[index];
            break;
        case '*':
            result *= list[index];
            break;
        default:
            break;
        }
        */
    }

    cout << endl << "The result base on your action (" << action << ") is :" << result;
}