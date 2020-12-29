#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float average(vector<int> numbers, size_t len);

int main()
{    
    vector<int> numbers;
    size_t count;
    int tempNumber, minNumber, maxNumber;

    system("cls");

    cout << "Enter count of numbers: ";
    cin >> count;

    for (int index = 0; index < count; index++)
    {
        cout << "Enter number(" << index+1 << "): ";
        cin >> tempNumber;
        numbers.push_back(tempNumber);
    }

    maxNumber = numbers.front();
    minNumber = numbers.front();
    for (int index = 1; index < count; index++)
    {
        maxNumber = max(maxNumber, numbers[index]);
        minNumber = min(minNumber, numbers[index]);
    }

    cout << "The average of the entered numbers is " << average(numbers, count) << endl;
    cout << "The minimum and maximum of the entered numbers are " << minNumber << " and " << maxNumber << " respectively." << endl;
}

float average(vector<int> numbers, size_t len)
{
    float sum = 0, average;
    for (int index = 0; index < len; index++)
    {
        sum += numbers[index];
    }
    average = (sum / len);
    return average;
}