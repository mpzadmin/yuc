#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float maxList(vector<float> numbers);
float minList(vector<float> numbers);
float averageList(vector<float> numbers);

int main(int argc, char const *argv[])
{
    int count;
    vector<float> numbers;

    cout << "Enter count number: "; 
    cin >> count;

    for(int i=1; i<=numbers.size(); i++)
    {
        cout << "Enter number(" << i << "):";
        numbers.push_back(cin.get());
    }

    cout << maxList(numbers) << endl;
    cout << minList(numbers) << endl;
    cout << avrageList(numbers) << endl;
}

float maxList(vector<float> numbers)
{
    float maxNumber;
    for(int i=0; i<numbers.size(); i++)
    {
        max(maxNumber,numbers[i]);
    }
    return maxNuber;
}

float minList(vector<float> numbers)
{
    float maxNumber;
    for(int i=0; i<numbers.size(); i++)
    {
        min(maxNumber,numbers[i]);
    }
    return maxNuber;
}

float averageList(vector<float> numbers)
{
    float average;
    for(int i=0; i<numbers.size(); i++)
    {
        average += numbers[i];
    }
    return average/numbers.size();
}