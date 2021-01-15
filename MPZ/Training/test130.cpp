#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    protected:
        string brand;
    public:    
        void setBrand(string brand);
        string getBrand();
};

class Car: public Vehicle
{
    public:
        string color;
        void showCar();
};

int main()
{
    Car car;


}

void Vehicle::setBrand(string brand)
{
    this->brand = brand;
}

string Vehicle::getBrand()
{
    return this->brand;
}

void Car::showCar()
{
    
    cout << this->color << endl;
}
