#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> numbers;
    
    for (int index=0; index<numbers.size(); index++) 
    {
        cout << numbers.at(index) << endl;
    }

    for(int number : numbers)
    {
        cout << number << endl;
    } 

    /*
    numbers.push_back(10);
    numbers.pop_back();
    numbers.front();
    numbers.back();
    numbers.at(0);
    numbers[0];
    numbers.size();
    numbers.capacity();
    numbers.empty();

    numbers.begin();
    numbers.end();
    numbers.insert(numbers.begin(),100);
    numbers.erase(numbers.end());
    numbers.clear();
    numbers.erase(numbers.begin(), numbers.end());
    x = numbers(numbers.begin(), numbers.end())
    */

}