#include<iostream>

using namespace std;
float function(int number);

int main()
{
    int number ;
    cout << "Enter a number:";
    cin>> number;
    cout << function (number);

}
size_t factor(int number)
{
    return (number <= 1) ?number :number *factor(number -1);
}
 float function(int number)
 {

     return(number==1) ? number : (1/( number * factor(number )) +  function(number-1));
 }