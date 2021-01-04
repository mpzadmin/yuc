#include <iostream>

using namespace std;

int *numbers;
int numbersCount = 0;

void push(int numbers[], int length, int value);

int main()
{
    int* num;
    num = new int[3];
    num[0] = 2;
    num[1] = 5;
    num[2] = 8;
    for (int i = 0; i < 3; i++)
    {
        cout << num[i] << " ";
    }
    cout << "\n";
    push(num, 3, 5);
    push(num , 4 , 6);
    push(num , 5 , 8);
    push(num , 6 , 9);
    for (int i = 0; i < 7; i++)
    {
        cout << num[i] << " ";
    }
}

void push(int numbers[], int length, int value)
{
    int pushHelper[length];
    for (int i = 0; i < length; i++)
    {
        pushHelper[i] = numbers[i];
    }
    delete []numbers;
    numbers = new int[length + 1];
    for (int i = 0; i < length; i++)
    {
        numbers[i] = pushHelper[i];
    }
    numbers[length] = value;
}