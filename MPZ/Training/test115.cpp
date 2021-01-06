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
    protected:
        string str;
};

float Box::area()
{
    return width * height;
}

int main()
{
    Box box;    
    box.height = 10;
    box.width = 100;
    cout << box.width << "\t" << box.height << endl;
    cout << "Area : " << box.area() << endl;
}