#include <iostream>

using namespace std;

void fact ( size_t number, int factorial=0 ); 

int main()
{
 int number;
 cout << "enter a number : ";
 cin >> number;


}

void fact ( size_t number=0, int factorial=0 )
{
    for ( int i=0; i <= number; i++ )
    {
    return ( number == 1 ) ? number : fact (number-1);

    }
}