#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    numbers.push_front(5);

    for (int number : numbers)
    {
        cout << number << "\t";
    }
}