#include <iostream>

using namespace std;
size_t n(size_t &number);
int main(int argc, char const *argv[])
{
    int number;
    cout << "Please enter your number: ";
    cin >> number;
    n(number);
    return 0;
}
size_t n(size_t number)
{
    float sum = 1;
    cout << "1";
    for (int i = number; i >= 1; i--)
    {
        return (number == 1) ? number : number * n(number-1);
        sum += 1/n(number);
        cout << "+" << "1/" << n(number);  
    }
    cout << "=" << sum;
    
}
