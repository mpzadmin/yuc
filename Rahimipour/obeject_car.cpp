#include <iostream>
#include <string>

using namespace std;

class Car
{
    public:
        string model;
        string brand;
        int year;
        Car(string b, string m, int y);
};

Car::Car(string b, string m, int y)
{
    brand = b;
    model = m;
    year = y;
};

int main()
{
    Car car;
}