#include <iostream>
#include <string>

using namespace std;

class Car
{
    public:
        string brand;
        string model;
        int year;
        Car() {}
        Car(string b, string m, int y);
};

Car::Car(string b, string m, int y)
{
    brand = b;
    model = m;
    year = y;
}

int main(int argc, char const *argv[])
{
    Car bmw("BMW", "X5", 2020);
    Car ford;
    ford.brand = "Ford";
    ford.model = "Mustang";
    ford.year = 1975;
}