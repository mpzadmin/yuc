#include <iostream>

using namespace std;

int main ()
{
  float number1, a; 
  float factorial=1;
  cout << "enter a number : ";
  cin >> number1;
  for (int i=1; i<=number1; i++)
   {
    factorial *= i;
   }
   a = factorial;
}