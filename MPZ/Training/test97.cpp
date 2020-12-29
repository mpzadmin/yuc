#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;
    int tempNumber;
    int count;
    int maxNumber, minNumber;

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
        cout << number << endl;

    }    
}