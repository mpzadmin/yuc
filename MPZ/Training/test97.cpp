#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;
    int tempNumber;
    int count;    
    int maxNumber, minNumber;
    float sum = 0;

    system("cls");
    cout << "Enter numbers count: ";
    cin >> count;

    for (int index=0; index<count; index++)
    {
        cout << "Enter number(" << index+1 << "): ";
        cin >> tempNumber;
        numbers.push_back(tempNumber); 
    }

    minNumber = numbers.front();
    maxNumber = numbers.front();
    
    for (int number : numbers)
    {
        if (number > maxNumber)
        {
            maxNumber = number;
        }
        if (number < minNumber)
        {
            minNumber = number;
        }
        sum += number;        
    }

    cout << "The maximum number is: " << maxNumber << endl;
    cout << "The minimum number is: " << minNumber << endl;
    cout << "The average is: " << (float) sum/numbers.size() << endl;    
}