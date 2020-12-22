#include <iostream>

using namespace std;

int main()
{
    int number = 100;
    int* ptr = &number;

    int list[5] = {1, 2, 3, 4, 5};
    int* listptr = list;

    cout << list[0] << list[1] << endl;
    cout << *(listptr+0) << *(listptr+1) << endl;

}

