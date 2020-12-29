#include <iostream>
#include <vector>

using namespace std;

float avg(vector<int> numbers, int count);

int main()
{
    int count;
    cout << "Enter a count of number: ";
    cin >> count;

    vector<int> numbers(count);

    for (int index=0; index < count; index++)
    {
        cout << "Enter number(" << index+1 << "): ";
        cin >> numbers[index];
    }

    cout << "The average of your number is: " << avg(numbers, count);
}

float avg(vector<int> numbers, int count)
{
    float sum = 0;
    for (int index=0; index < count; index++)
    {
        sum += numbers[index];
    }
    float avg = sum/count;
    return avg;
}