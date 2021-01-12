#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    public:
        string brand;
};

class Device
{
    public:
        string color;
};

class SmallCar: public Vehicle, public Device
{
    public:
        float power;
};

int main()
{
    SmallCar sc;
    


}