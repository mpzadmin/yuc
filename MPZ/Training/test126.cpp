#include <iostream>
#include <string>

using namespace std;

class Vehicle {
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

int main()
{
    Vehicle car("BMW");

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