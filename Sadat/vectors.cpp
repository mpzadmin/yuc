#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<int> number;
    int count, maxNumber, minNumber, sum = 0, help;
    float average;

    cout << "Enter count of numbers: ";
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> help;
        number.push_back(help);
    }
    minNumber = help;
    maxNumber = help;
    for (size_t i = 0; i < count; i++)
    {
        maxNumber = max(maxNumber, number.at(i));
        minNumber = min(minNumber, number.at(i));
        sum += number.at(i);
    }
    average = (float) sum/(float) count;
    cout << "Max number is: " << maxNumber << endl;
    cout << "Min number is: " << minNumber << endl;
    cout << "Average is: " << average << endl;
}