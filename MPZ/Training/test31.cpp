/* Developer: Masoud PourZahmatkesh */
#include <iostream>

using namespace std;

int main()
{
    for (int index = 1; index <= 10; index++)
    {
        if (index == 2) continue;
        if ( index >= 5 ) break;
        cout << index << endl;
    }    
}