#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float number = 100;
    float average = number/3;

    cout << average << endl;
    cout << setprecision(3) << average << endl;     // 33.3
    cout << fixed;
    cout << setprecision(3) << average << endl;     // 33.333
    cout << defaultfloat;
    cout << scientific;
    cout << setprecision(3) << average << endl;     // 33.333e+01
    cout << defaultfloat;
}