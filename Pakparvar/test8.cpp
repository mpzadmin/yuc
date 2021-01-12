#include <iostream>
using namespace std;
size_t factorial(size_t n);
int main()
{
    float n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "1/" << factorial(n) << endl;
}
size_t factorial(size_t n)
{
    
    return (n ==1) ? n : n * factorial(n - 1);
    
}