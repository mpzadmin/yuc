#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr;

    ptr = find(numbers, numbers+5, 30);
    if (ptr != numbers+5)
    {
        cout << "FOUND: " << *ptr << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }

}