#include <iostream>
#include <string>

using namespace std;

class Car
{
    private:
        string brand;
        string model;
        int year;
    public:
        void setBrand(string b);
        string getBrand();
        void setModel(string m);
        string getModel();
        void setYear(int y);
        int getYear();
        void showInfo();
};

void Car::setBrand(string b)
{
    // validate brand
    brand = b;
}

string Car::getBrand()
{
    return "*[" + brand + "]*";
}

void Car::setModel(string m)
{
    // validate model
    model = m;
}

string Car::getModel()
{
    return "(" + model + ")";
}

void Car::setYear(int y)
{
    // validate year
    year = y;
}

int Car::getYear()
{
    return year;
}

void Car::showInfo()
{
    cout << getBrand() << " " << getModel() << " " << getYear() << endl;
}

int main()
{
    Car bmw;
    Car *car = &bmw;

    bmw.setBrand("BMW");
    bmw.setModel("850i");
    bmw.setYear(2020);
    
    cout << bmw.getBrand() << " " << bmw.getModel() << " " << bmw.getYear() << endl;
    bmw.showInfo();
    car->showInfo();
}