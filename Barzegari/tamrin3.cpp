#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxList(vector<int> numbers);
int minList(vector<int> numbers);
float averageList(vector<int> numbers);

int main(int argc, char const *argv[])
{
    int count, tempNumber;
    vector<int> numbers;

    cout << "Enter count number: "; 
    cin >> count;

    for(int i=1; i<=count; i++)
    {
        cout << "Enter number(" << i << "):";
        cin >> tempNumber;
        numbers.push_back(tempNumber);
    }

    cout << maxList(numbers) << endl;
    cout << minList(numbers) << endl;
    cout << averageList(numbers) << endl;
}

int maxList(vector<int> numbers)
{
    int maxNumber = -32768;
    for(int i=0; i<numbers.size(); i++)
    {
        maxNumber = max(maxNumber,numbers[i]);
    }
    return maxNumber;
}

int minList(vector<int> numbers)
{
    int minNumber = 32767;
    for(int i=0; i<numbers.size(); i++)
    {
        minNumber = min(minNumber, numbers[i]);
    }
    return minNumber;
}

float averageList(vector<int> numbers)
{
    float average;
    for(int i=0; i<numbers.size(); i++)
    {
        average += numbers[i];
    }
    return (float)(average/numbers.size());
}