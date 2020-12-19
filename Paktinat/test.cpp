#include <iostream>

using namespace std;

int mymax(int a, int b);
float mymax(float b, float a);
double mymax(double a, double b);

int main()
{
  cout << mymax(87676468.67, 9254.2846);
}

int mymax (int a, int b )
{
    int result;
    if ( a > b )
      result = a;
    else
      result = b;

    return result;

    void display(string str);
    void display(string str, bool newline);

    int main()
    {
      display("hello", true);
      display("welcom");
      display("bye",true);
    }     
      
}