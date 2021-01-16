#include <iostream>
#include <string>

using namespace std;
class Car
{
    private:
        string brand;
        string color;
    public:
        void setBrand(string brand);
        string getBrand();
        void setColor(string color);
        string getColor();
        void debug();
        
};

int main()
{
    Car car;
    car.setColor("Black");
    car.setBrand("Benz");
    car.debug();
}

void Car::setBrand(string brand)
{
    this->brand = brand;
}

string Car::getBrand()
{
    return this->brand;
}

void Car::setColor(string color)
{
    this->color = color;
}

string Car::getColor()
{
    return this->color;
}

void Car::debug()
{
    cout << "Brand: " << this->brand << "\t" << "Color: " << this->color << endl;
}
