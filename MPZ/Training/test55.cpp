#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int minRandomNumber = 1;
const int maxRandomNumber = 100;

int main()
{
    int number;
    
    srand((unsigned) time(0));
    for (int index=1; index <= 5; index++)
    {
        //number = (rand() % 100) + 1;       // 1 - 100
        //number = (rand() % 30) + 1985;       // 1985 - 2014
        number = minRandomNumber + (rand() % (maxRandomNumber - minRandomNumber)) + 1;
        cout << number << endl;
    }
    
}