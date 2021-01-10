#include <iostream>

using namespace std;

class Box 
{
    private:
        int number;
    public:
        float width;
        float height;
    float area();    
};

float Box::area()
{
    return width * height;
}

int main()
{
    system("cls");
    Box box;
    box.height = 10;
    box.width = 2.5;

    cout << "The area is: " << box.area();
}