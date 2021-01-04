#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int numberCount, takeNumber, searchFor;
    list<int> numbers;
    list<int>::iterator it;

    numbers.push_back(50);
    numbers.push_back(40);
    numbers.push_back(30);
    numbers.push_back(20);
    numbers.push_back(10);

    it = find(numbers.begin(), numbers.end(), 101);
    if (it != numbers.end())
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }
    

}