#include <iostream>
#include <string>

using namespace std;

class Utility
{
    private:
        int value;
    public:
        const static int number = 1000;
        static void display(string str)
        {
            cout << str << endl;            
        }
        static int max(int a, int b)
        {
            return a > b ? a : b;
        }
};

int main()
{
    //Utility u;
    //cout << u.number << endl;
    Utility::display("Hello"); 
    cout << Utility::max(10,14) << endl;
    cout << Utility::number << endl;  
}