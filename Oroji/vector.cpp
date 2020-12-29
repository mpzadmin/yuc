#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;
int main() 
{  
     int tedad;
     float adad, avg, sum=0;
    vector<float>numbers;
    cout << "enter tedad: " << endl;
    cin >> tedad;
    for(int i=0 ; i< tedad ;i++)
    {   
        cout << "enter number "<< i+1 <<" is: " << endl;
        cin >> adad;
        numbers.push_back(adad); 
    }
     for(int i=0 ; i< tedad ;i++)
    {
        sum +=numbers[i];
    }
    avg = sum/tedad;
    cout << " average is: " << (float)avg  << endl; 
    cout << " max number: " << max(numbers.front(),numbers.back()) << endl;
    cout << " min number: "<< min(numbers.front(),numbers.back()) << endl;
}