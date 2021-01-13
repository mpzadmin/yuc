#include <iostream>
#include <string>

using namespace std;

class car 
{
    private:
        string brand;
        string model;
    public:
        car* setbrand(string brand);
        car* setmodel(string model);
        car* debug();

        string getbrand();
        string getmodel();    
};

car* car:: setbrand(string brand)
{
    this->brand=brand;
    return this;
}

car* car:: setmodel(string model)
{
    this->model=model;
    return this;
}

car* car:: debug()
{
    cout << "brand : " << brand << "\t" << "model : " << model << endl;
    return this;
}

string car:: getbrand()
{
    return brand;
}

string car:: getmodel()
{
    return model;
}

int main(int argc, char const *argv[])
{
    car* c;
    c = new car;

    c
       ->setbrand("bmw")
       ->setmodel("m4")
       ->debug();

    c->setbrand("ford")->setmodel("mustang")->debug();
    delete c;





    return 0;
}


