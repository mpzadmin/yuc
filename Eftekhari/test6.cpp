#include <iostream>
using namespace std ;
int fact(int number);
float series(float number);

int main(int argc, char const *argv[])
{
    int number ;
    cout <<"Enter a number" ;
    cin >> number ;
    cout << "The series "<< number << "Is" << series(number) << endl ;
    


    
    return 0;
}
int fact(int number)
{
    return (number == 1) ? 1 : number * fact(number - 1);
}
float series(float number)
{
    return(number == 1) ? number : (1/(float)fact(number)) + series(number - 1);
}