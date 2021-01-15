#include <iostream>
#include <string>

using namespace std;

class Car
{
    public:
        void showInfo()
        {
            cout << "This is Car class" << endl;
        }
};

class Bmw: public Car
{
    public:
        void showInfo()
        {
            cout << "This is Bmw class" << endl;
        }
};

class Samand: public Car
{
    public:
        void showInfo()
        {
            cout << "This is Samand class" << endl;
        }
};

int main()
{
    // Polymorphism
    Bmw b;
    Samand s;

    b.showInfo();
    s.showInfo();
}