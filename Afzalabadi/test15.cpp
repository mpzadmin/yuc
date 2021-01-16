#include<iostream>
#include <string>

using namespace std;

class Car 
{
    private:
        string brand;
        string model;
        int year;
    public:
       void setBrand(string brand) ;
       string getBrand();
       void setModel(string model);
       string getModel();
       void setYear(int year);
       int getYear();    
};
void Car::setBrand(string brand)
 {
    brand = brand;
 } 
string Car:: getBrand()
 {
    return"(" +brand + ")";

 }
 void ::setModel(string model)
 {
     model = model;
 }
 string Car:: getModel()
 {
     return"[" + model +"]";
 }
 void Car::setYear (int year)
 {
     year = year;

 }
 int Car :: getYear()
 {
     return year;
 }

int main()
{
    Car bmw;
    Car ford;
     bmw.setBrand("BMW");
     bmw.setModel("i8");
     bmw.setYear(2016);
    
     ford.setBrand("ford");
     ford.setModel("mustang");
     ford.setYear(2010);
 
    cout << bmw.getBrand() << "   "  << bmw.getModel() << "   " << bmw.getYear()  << "    " << endl;
    cout << ford.getBrand() << "   "  << ford.getModel() << "   " << ford.getYear()  << "    " << endl;


    
}