#include <iostream>

using namespace std;

void sortlist(int *n ,int a);

int main()
{
    int *n;
    int a;

    cout << "Enter a count of: ";
    cin >> a;

    n = new int[a];

    for (int i = 1; i <= a; i++)
    {
        cout << "Enter number {" << i << "} : ";
        cin >> n[i - 1];
    }

    sortlist(n ,a);

    delete[] n;
    return 0;
}

void sortlist(int *n ,int a)
{
    int number;
    for (int i = 0; i < a; i++)
    {
        for (int i = i + 1; i < a ; i++)
        {
            if (*(n + i) > *(n + i))
            {
                number = *(n + i);
                *(n + i) = *(n + i);
                *(n + i) = number;
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        cout << *(n + i) << " ";
    }
}