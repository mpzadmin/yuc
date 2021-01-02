#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
   float avarage ;
    int  maxNumber,minNumber;
    int number , count;
    float sum = 0;

    vector <int> numbers;

    cout <<"Enter count of your numbers:" << endl;
    cin >> count;

    for (int index= 0;index<count; index++)
     {
        cout << "enter number[" << index+1 << "]" <<endl;
        cin >> number;
        numbers.push_back(number);
     }
    
    for(int number1 : numbers)
    {
        sum+= number1;

    }
    maxNumber= numbers.front();
    minNumber= numbers.front();
    for (int index= 0; index<count; index++)
    {
      maxNumber  =  max(maxNumber,numbers[index]);
      minNumber = min(minNumber,numbers[index]);

     }
     cout << "The maxnumber is:" << maxNumber << endl;
     cout << "The minnumber is:"  << minNumber  << endl;      
     avarage = (sum / count);
     cout << "The avarage is:" << (float) avarage;

}


