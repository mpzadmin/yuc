#include <iostream> 

using namespace std;

int main()
{
    int number, e=0;
    cout << "enter number : ";
    cin >> number;
    for (int i=1; i <= number; i++ )
    {
        if ( (i % 2) == 0 )
        {
         e++;
        }
    }
    cout << "even : " << e << endl;
}