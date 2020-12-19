#include <iostream>

using namespace std;

int main()
{
    int number = 100;
    
    int &myNumber = number;    

    cout << number << endl;
    cout << myNumber << endl;

}