#include <iostream>
#include <string>

using namespace std;

size_t factorial (size_t number);
float bazgashti (float number);


int main()
{ 
  size_t number = 2;
/*cout << "Enter a number";
  cin >> number;*/

  cout << "the factorial is: " << factorial (number) << endl;
  cout << "the result of series:  " << (float) bazgashti (number) << endl;
}

size_t factorial (size_t number)
{
    return (number <= 1) ? number : number * factorial (number - 1);
}

float bazgashti (float number)
{
  return (number == 1) ? number :  (1/(float)factorial(number) + bazgashti (number - 1));

}