#include <iostream>

using namespace std;

float factorial(int number);
float seri(int N);

int main()
{
    int N;
    cout << "Enter a number for Numerical series calculation: ";
    cin >> N;

    cout << seri(N);
}

float factorial(int number)
{
    return (number == 1) ? number : number * factorial(number-1);
}

float seri(int N)
{
    return (N == 1) ? N : 1/factorial(N) + seri(N-1);
}
