#include <iostream>

using namespace std;

int main()
{
    int counter = 1;
    while (counter <= 5)
    {
        cout << counter << endl;
        counter++;
    }

    counter = 1;
    do {
        cout << counter << endl;
        counter++;    
    } while (counter <= 5);
    
}