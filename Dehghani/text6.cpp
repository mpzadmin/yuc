#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{   int count;
    int tempNumber;
    int maxNumber;
    int minNumber;
    int sum = 0;

    vector <int> numbers;

    cout << "Enter count of number : ";
    cin >> count;

    for (int index = 0; index < count; index++)
    {
        cout << "enter number  ( " <<  index +1  << ") :" << endl;
        cin >> tempNumber;

        numbers.push_back(tempNumber);
    }

    minNumber = numbers.front();
    maxNumber = numbers.front();

   /* for (int index = 0; index < numbers.size(); index++)
    {
        cout << numbers.at(index)  << endl;
    }
    */
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
         sum += number;          /*sum + number = number*/
    }
    cout << "The maximum number is: " << maxNumber << endl;
    cout << "The minimum number is: " << minNumber << endl;
    cout << "The average is: " << (float) sum/numbers.size() << endl;    

    return 0;
}
