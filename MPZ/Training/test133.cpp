#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        string brand;
        string color;
    public:
        Car* setBrand(string brand);
        Car* setColor(string color);
        Car* debug();

        string getBrand();        
        string getColor();
};

int main()
{
    Car* car;

    car = new Car;
    
    car->setBrand("BMW")->setColor("Black")->debug();
    car
        ->setBrand("Ford")
        ->setColor("White")
        ->debug();

    //car->list()->filterByPower(1000)->sort()->show();

    delete car;
}

Car* Car::setBrand(string brand)
{
    this->brand = brand;
    return this;
}

Car* Car::setColor(string color)
{
    this->color = color;
    return this;
}

Car* Car::debug()
{
    cout << "Brand = " << this->brand << "\t" << "Color = " << this->color << endl;
    return this;
}

string Car::getBrand()
{
    return this->brand;
}

string Car::getColor()
{
    return this->color;
}

