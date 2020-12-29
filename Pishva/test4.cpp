#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int countNumbers;
    int maxNumbers, minNumbers;
    double sum, average;
    int number;

    system("cls");

    cout << "Enter count of numbers: ";
    cin >> countNumbers;

    vector<int> numbers(countNumbers);

    system("cls");

    for (int index = 0; index < countNumbers; index++)
    {
        cout << "Enter number (" << index+1 << "): ";
        cin >> number;
        numbers.at(index) = number;
        numbers.push_back(numbers.at(index));
    }

    system("cls"); 

    maxNumbers = max(numbers.at(0), numbers.at(1));

    for (int index = 2; index < countNumbers; index++)
        maxNumbers = max(maxNumbers, numbers.at(index));

    
    cout << "Max of numbers is: " << maxNumbers << endl;

    minNumbers = min(numbers.at(0), numbers.at(1));

    for (int index = 2; index < countNumbers; index++)
        minNumbers = min(minNumbers, numbers.at(index));

    cout << "Min of numbers is: " << minNumbers << endl;

    for (int index = 0; index < countNumbers; index++)
        sum = sum + numbers.at(index);

    average = sum / countNumbers;

    cout << "Average of numbers is: " << average << endl;

    return 0;
}