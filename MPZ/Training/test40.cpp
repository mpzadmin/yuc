#include <iostream>

using namespace std;

int main()
{
    float number = 100;
    float average = number/3;
    cout << average << endl;

    // casting        int (x)       (int) x
    cout << int(average) << endl;   // function
    cout << (int) average << endl;  // c-base
}