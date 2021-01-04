#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

typedef list<int>::iterator IntListIterator;

int main()
{
    list<int> numbers;
    list<int>::iterator it;

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

    cout << endl;
    numbers.remove(30);
    numbers.remove(5);

    it = find(numbers.begin(), numbers.end(), 20);
    if (it != numbers.end())
    {
        cout << "FOUND: " << *it << endl;
        numbers.erase(it);
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }


    for (IntListIterator index=numbers.begin(); index!=numbers.end(); index++)
    {
        cout << *index << "\t";
    }

    it = numbers.begin();
    advance(it, 4);
    cout << endl << *it << endl;

    numbers.insert(numbers.begin(), 1000);    

}