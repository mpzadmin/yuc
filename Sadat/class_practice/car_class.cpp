#include <iostream>

using namespace std;

class Car
{
    public:
        string brand;
        string model;
        int year;
        Car(string b, string m, int y);
        Car();
};

int main()
{

}

Car::Car(string b, string m, int y)
{
    brand = b;
    model = m;
    year = y;
}

Car::Car(){}