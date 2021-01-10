#include <iostream> 
#include <iomanip>

using namespace std;

void delay(int a);

int main()
{
    int a, t;
    cout << "enter anumber : ";
    cin >> a;
    cout << "enter anumber : ";
    cin >> t;
    for (int i=1; i <= a; i++)
    {
      cout << "_ ";
      delay(500000);
    }
    for (int i=1; i <= t; i++)
    {
        cout << setw(2*a) << "|" << endl;
        delay(50000050);
        cout << "|";
    }
     for (int i=1; i <= a; i++)
    {
      cout << "_ ";
      delay(500000);
    }

}


void delay(int a)
{
    for ( int i=0; i<=2*a; i++)
    {
        for (int i; i <= 555000; i++);
    }
}







