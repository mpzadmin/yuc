#include <iostream>

using namespace std;

class Box
{
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
    Box box;
    box.height=5;
    box.width=10;

    cout << box.height << "  " << box.width << endl;
    cout << "Area: " << box.area() << endl;
}