#include <iostream>
using namespace std;
int myMax(int a, int b);
float myMax(float a, float b);
double myMax(double a, double b);

int main()
{
    
    cout << myMax(65536676.73664, 333345678.7443433);
}
int myMax(int a, int b )
{
    int result;
    if(a > b)
    result = a;
    else
    result = b;
    return result;
}
float myMax(float a, float b)
{
      int result;
    if(a > b)
    result = a;
    else
    result = b;
    return result;
}
double myMax(double a, double b)
{
      int result;
    if(a > b)
    result = a;
    else
    result = b;
    return result;
}