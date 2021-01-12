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
    brand  = b;
    model = m; 
    year = y;
    cout << "Class init car" << endl;
    cout << brand << " " << model << " " << year << endl;
}
Car::~Car()
{
    cout << "Destruct car class" << endl;
}
int main()
{
    
    Car benz("Mercedes-Benz", "C200", 2019 );
}