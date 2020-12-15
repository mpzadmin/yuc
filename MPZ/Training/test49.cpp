#include <iostream>

using namespace std;

const int maxList = 10;
int main()
{
    int list[maxList];
    list[0] = 100;          // first one
    list[maxList-1] = 2;    // last one

    cout << sizeof(list);
}