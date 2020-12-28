#include <iostream>

using namespace std;

size_t factorial(size_t number);

int main()
{
    cout << factorial(4) << endl;
}

size_t factorial(size_t number)
{
    return (number == 1) ? number : number * factorial(number - 1);

}
