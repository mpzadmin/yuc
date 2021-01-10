#include <iostream>
#include <string>

using namespace std;

class Car
{
    public:
        string brand;
        string model;
        int year;
        Car ();
};
Car::Car()
{

};

int main()
{
    Car bmw;
    bmw.brand = "bmw";
    bmw.model = "m4";
    bmw.year = 2016;
    
    cout << bmw.brand << ", " << bmw.model << ", " << bmw.year << "." << endl;

}