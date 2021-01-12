#include <iostream>
#include <string>
using namespace std;

class Car
{
    private:
        string model;
        string brand;
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
    brand = b;
}
string Car::getBrand()
{
    return "[" + brand + "]";
}
void Car::setModel(string m)
{
    model = m;
}
string Car::getModel()
{
    return "[" + model + "]";
}
void Car::setYear(int y)
{
    year = y;
}
int Car::getYear()
{
    return  year;
}
void Car::showInfo()
{
    cout << getBrand() << getModel() << getYear() << endl;
}
int main()
{
    system("cls");
    Car Benz;
    Benz.setBrand("Mercedes-Benz");
    Benz.setModel("C200");
    Benz.setYear(2019);
    cout << Benz.getBrand() << " " << Benz.getModel() << " " << Benz.getYear() << endl;
    Benz.showInfo();
}