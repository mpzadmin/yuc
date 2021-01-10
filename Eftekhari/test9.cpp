#include <iostream>
using namespace std ;


class Box
{
    public:
       float heigth;
       float width;
       float mohit();
       float masahat();

};
float Box::mohit()
{
    return 2*(width+heigth);
}
float Box::masahat()
{
    return width*heigth;
}


int main(int argc, char const *argv[])
{
    Box box1 , box2 ;
    box1.heigth=8 ;
    box1.width=3;
    box2.heigth=9;
    box2.width=3;
    cout<<"Mohit:"<<box1.mohit() <<endl;
    cout<<"masahat: " <<box2.masahat()<<endl;
    return 0;
}
