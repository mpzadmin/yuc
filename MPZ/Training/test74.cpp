#include <iostream>

using namespace std;

int main()
{
    int number = 100;
    int* ptr = &number;

    cout << number << endl;
    cout << *ptr << endl;
    
    int list[5] = {1, 2, 3, 4, 5};
    int* listPtr = list;

    char list2[5] = {'A', 'B', 'C', 'D', 'E'};
    char* listPtr2 = list2;

    cout << list[0] << "\t" << list[1] << endl;
    cout << listPtr[0] << "\t" << listPtr[1] << endl;
    cout << *(listPtr+0) << "\t" << *(listPtr+1) << endl;    
}