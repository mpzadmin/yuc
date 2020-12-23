#include <iostream>

using namespace std;

void printNumbers(int numbers[], size_t len);
void sortNumbers(int numbers[], size_t len);

int main()
{
    int numbers[6] = {15, 3, 11, 1, 9, 7};

    system("cls");

    for (int number : numbers)
    {
        cout << number << endl;
    }
    
    printNumbers(numbers, 6);
    sortNumbers(numbers, 6);
    printNumbers(numbers, 6);
}

void printNumbers(int numbers[], size_t len)
{    
    for (int index=0; index<len; index++)
    {
        cout << numbers[index] << "\t";
    }
    cout << endl;
}

void sortNumbers(int numbers[], size_t len)
{
    int number;
    if (len <= 0)
    {
        return;
    }

    for (int i=0; i<len-1; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (numbers[i] > numbers[j])
            {
                number = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = number;
            }
        }
    }    
}