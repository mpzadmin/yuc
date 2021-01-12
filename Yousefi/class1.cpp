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
    cout << "car class init"<< endl;
}

Car::Car(string b, string m, int y)
{
    brand = b;
    model = m;
    year = y;
    cout << "car class init"<<endl;
    cout<< brand << " " << model << " " << year <<endl;
}

Car:: ~Car()
{
    cout<< "Destrcut Car class" << endl;
}

int main(int argc, char const *argv[])
{
    Car Bmw("BMW","X4",2016);

    Car* ford;

    ford= new Car [1];

    Car ford ("ford","mustung", 1976);

    delete ford;

    return 0;
}
