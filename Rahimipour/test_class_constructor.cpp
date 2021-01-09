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
        Car(string b, string model, int y);
};

Car::Car()
{
    cout << "AtuoGalley" << endl;
}


Car::Car(string b, string m, int y)
{
    model = m;
    brand = b;
    year = y;
    cout << brand << ":" << model << ":" << year << endl;
}

Car::~Car();


int main()
{
    Car MercedesBenz;
    Car bmw ("bmw", "m4", 2012);

    MercedesBenz.brand = "Mercedes-Benz";
    MercedesBenz.model = "x250";
    MercedesBenz.year = 2020;
    cout << MercedesBenz.brand << ":" << MercedesBenz.model << ":" << MercedesBenz.year << endl;     
}