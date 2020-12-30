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

    // get numbers
    for (int index = 0; index < count; index++)
    {
        cout << "Enter number " << (index + 1) << " : ";
        cin >> number;
        numbers.push_back(number);
    }

    // printing numbers
    cout << endl << "Your numbers are: ";
    for (int index = 0; index < count; index++)
    {
        cout << numbers.at(index) << "\t";
    }
    cout << endl << endl;

    // sum numbers
    for (int index = 0; index < count; index++)
    {
        sum += numbers.at(index);
    }

    // calculate average
    average = (float) sum / (float) count;
    cout << "Average = " << average << endl;

    int max = numbers.front();
    int min = numbers.front();

    // calculatimg Maximum and Minimum
    for (int index = 0; index < count; index++)
    {
        if (numbers.at(index) > max)
            max = numbers.at(index);

        if (numbers.at(index) < min)
            min = numbers.at(index);
    }

    cout << "Maximum = " << max << "\nMinimum = " << min;

    return 0;
}