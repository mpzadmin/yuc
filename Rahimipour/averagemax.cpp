// some help from pishva project
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int numberCount, number, maxNumber, minNumber;
    float sum = 0 , average;
    system("cls");

    cout << "Enter a number: ";
    cin >> numberCount;
    vector<int> vec(numberCount);

    for (int index = 0; index < numberCount; index++)
    {
        cout << "Enter number (" << index + 1 << ") : ";
        cin >> number;

        vec.at(index) = number;
        vec.push_back(vec.at(index));
    }

    maxNumber = max(vec.at(0), vec.at(1));
    minNumber = min(vec.at(0), vec.at(1));

    for (int index = 2; index < numberCount; index++)
    {
        maxNumber = max(maxNumber, vec.at(index));
        minNumber = min(minNumber, vec.at(index));
    }

    for (int index = 0; index < numberCount; index++)
    {
        sum += vec.at(index);
    }

    average = (sum/numberCount);
    system("cls");

    cout << "The max number is: " << maxNumber << endl;
    cout << "The min number is: " << minNumber << endl;
    cout << "The average is: " << average << endl;
}