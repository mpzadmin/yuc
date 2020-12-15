/* Developer: Masoud PourZahmatkesh */
#include <iostream>

using namespace std;

const int delayValue = 10000000;

int main()
{
    system("cls");
    for (int index  = 1; index <= 50; index++)
    {
        cout << "_";
        for (int counter = 1; counter <= delayValue; counter++);        
    }


    //system("pause");
}