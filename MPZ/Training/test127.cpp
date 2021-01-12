#include <iostream>
#include <string>

using namespace std;

class Vehicle 
{
    private:
        float power;
    public:
        string brand;
        Vehicle();
        Vehicle(string brand);
        ~Vehicle();
        void setPower(float power);
        float getPower();  
};

class Car: public Vehicle
{
    private:
        string color;
    public:
        Car();
        Car(string brand, string color);
        ~Car();
        void setColor(string color);
        string getColor();
};

int main()
{
    //Vehicle v = Vehicle("BMW");
    Car car = Car("BMW", "Black");
    car.setPower(1000);    
    //car.setColor("Blue");
}

Vehicle::Vehicle()
{
    cout << "Init vehicle class" << endl;
}

Vehicle::Vehicle(string brand)
{
    cout << "Init vehicle class" << endl;
    this->brand = brand;
    cout << "Set brand to " << brand << endl;    
}

Vehicle::~Vehicle()
{
    cout << "Destroy vehicle class" << endl;
}

void Vehicle::setPower(float power)
{
    this->power = power;
}

float Vehicle::getPower()
{
    return this->power;
}

Car::Car()
{
    cout << "Init car class" << endl;
}

Car::Car(string brand, string color)
: Vehicle(brand)
{
    cout << "Init car class" << endl;    
    this->color = color;
    cout << "Set color to " << color << endl;
}


Car::~Car()
{
    cout << "Destroy car class" << endl;
}

void Car::setColor(string color)
{
    this->color = color;
}

string Car::getColor()
{
    return this->color;
}
