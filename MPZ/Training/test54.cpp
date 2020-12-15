#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int number;

    srand((unsigned) time(0));
    for (int index=1; index <= 5; index++)
    {
        cout << rand() << endl;
    }
}