#include <iostream>
#include <string>

using namespace std;

class Car
{
    public:
        string brand;
        string model;
        int year;
        Car();
        Car(string b, string m, int y);
        ~Car();
};

Car::Car()
{
    cout << "Car class init" << endl;
}

Car::Car(string b, string m, int y)
{    
    brand = b;
    model = m;
    year = y;
    cout << "Car class init" << endl;
    cout << brand << " " << model << " " << year << endl;    
}

Car::~Car()
{
    cout << "Destrcut Car class" << endl;
}

int main()
{
    Car *ford;
    Car bmw("BMW", "X5", 2020);
    
    //
    //
    //

    ford = new Car;

    //
    //

    delete[] ford;
    
}