#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    public:
        string brand;
};

class Car: public Vehicle
{
    public:
        string color;
};

class SmallCar: public Car
{
    public:
        float power;
};

int main()
{
    SmallCar sc;
    sc.


}