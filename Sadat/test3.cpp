#include <iostream>

using namespace std;

int main()
{
    int* number;
    number = new int[1];
    number[0] = 1;
    for (int i = 0; i < 1; i++)
    {
        cout << number[i] << " " << endl;
    }
    delete []number;
}