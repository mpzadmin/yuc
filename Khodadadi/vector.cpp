#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char** argv) 
{
    int count, number;
    float average;
    int sum = 0;

    vector<int> numbers;

    system("cls");
    cout << "Enter count of numbers: ";
    cin >> count;

    for (int index = 0; index < count; index++)
    {
        cout << "Enter number " << (index + 1) << " : ";
        cin >> number;
        numbers.push_back(number);
    }

    cout << endl << "Your numbers are: ";
    for (int index = 0; index < count; index++)
    {
        cout << numbers.at(index) << "\t";
    }
    cout << endl << endl;

    for (int index = 0; index < count; index++)
    {
        sum += numbers.at(index);
    }

    average = (float) sum / (float) count;
    cout << "The average is " << average << endl;

    int max = numbers.front();
    int min = numbers.front();

    for (int index = 0; index < count; index++)
    {
        if (numbers.at(index) > max)
            max = numbers.at(index);

        if (numbers.at(index) < min)
            min = numbers.at(index);
    }

    cout << "The maximum is " << max << "and minimum " << min;

    return 0;
}