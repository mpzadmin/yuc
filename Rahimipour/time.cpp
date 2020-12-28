// Developer : Ahad Rahimipour
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int hour = 0, minute = 0, second = 0, time;
    cout << "Enter a number as time: ";
    cin >> time;
    
    cout << endl;

    if (time <= 0)
    {
        SetConsoleTextAttribute(consoleHandle, 4);
        cout << "Error";
    }
    else
    {
        if ((0 < time) && (time < 60))
        {
            SetConsoleTextAttribute(consoleHandle, 2);
            second = time;
            cout << "Time is: " << second << " s";
        }
        else
        {
            minute = time / 60;
            if (minute < 60)
            {
                SetConsoleTextAttribute(consoleHandle, 3);
                second = time - (60 * minute);
                cout << "Time is: " << minute << " min " << second << " s";
            }
            else
            {
                hour = minute / 60;
                second = time - (minute * 60);
                minute = minute - (hour * 60); 
                SetConsoleTextAttribute(consoleHandle, 5);
                cout << "Time is: " << hour << " h " << minute << " min " << second << " s";
            }
        }
    }
}