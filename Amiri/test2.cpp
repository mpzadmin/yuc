#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<int> numbers;
    int number;
    int count;

    cout << "enter a number: ";
    cin >> number;

    

    for (int i=0; i<number; i++)
    {
        cin >> count;
        numbers.push_back(count);
    }


    int sum=0;
    for (int j=0; j<number; j++)
    {
        sum += numbers[j];
    }

    cout << sum/number;
}