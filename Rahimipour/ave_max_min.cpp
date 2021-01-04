#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    vector<int> numbers;
    int number, numberCount, minNumber, maxNumber, sum = 0;
    float average;

    system("cls");
    cout << "Enter a number count: ";
    cin >> numberCount;

    for(int index = 0; index < numberCount; index++)
    {
        cout << "Enter number(" << index+1 << "): ";
        cin >> number;
        numbers.push_back(number);
    }

    minNumber = number;
    maxNumber = number;

    for (int index = 0; index < numberCount; index++)
    {
        minNumber = min(minNumber, numbers.at(index));
        maxNumber = max(maxNumber, numbers.at(index));
        sum += numbers.at(index);
    }
    average = (float)sum/(float)numberCount;
    cout << "The maxnumber is: " << maxNumber << endl;
    cout << "The minnumber is: " << minNumber << endl;
    cout << "Average is: "       << average   << endl;

    // some help from sadat folder.
    
}