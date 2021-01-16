#include<iostream>
#include<string>

using namespace std;

class vehicle
{
    string power;
     string brand;
     public:
       void setpower(string power){
            this->power=power;

       };
       string setpower()
       {
           return power;
       }
       vehicle(string brand)
       {
           this->brand =brand;
           cout<< "vehicle class init"<<endl;
           cout<<"this brand is: "<<brand<<endl;
       }
       vehicle()
       {
           cout<<"class vehicle init"<<endl;
       }

      
       ~vehicle();
};


vehicle:: ~vehicle()
{
    cout<<"destroy class us";
}

class car: public vehicle
{ 
    public:

   car();
   
        
   
};

int main()
{
    car mrx;
}
    
