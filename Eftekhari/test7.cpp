#include <iostream>
#include <vector>
using namespace std ;

float average(std :: vector<int>numbers, int count);

int main(int argc, char const *argv[])
{
    int count ;
    cout <<"Enter a count of number: " ;
    cin >> count ;
    vector <int> numbers(count);

    for (int index = 0;index < count; index++)
    {
        cin >>numbers[index];

    }
    cout <<"The average is :" << average(numbers,count) ;
        
}
float average(std :: vector<int>numbers, int count)
{
    float sum = 0 ;
    for (int index = 0; index < count; index++)
    {
        sum += numbers[index];
        
    }
    float average = sum/count ;
    return average;
}