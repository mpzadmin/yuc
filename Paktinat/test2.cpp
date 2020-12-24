#include <iostream>

using namespace std;

int main ()
{
    int unsigned number; 
    int factorial=1;
    cout << "enter a positive number : ";
    cin >> number;
     if ((number == 0) || (number<0))
        {
            cout << "error" << endl;
            return 0;
        }
    for (int i=1; i<=number; i++)
    {
        factorial *= i;
    }
    cout << factorial;
    return 0;
}