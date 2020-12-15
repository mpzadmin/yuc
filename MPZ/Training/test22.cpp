#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) 
{
    int number = 10;   
    //number == 10 ? cout << "1" : cout << "2";

    if (number > 10)
    {
        cout << "number > 10" << endl;
    }
    else if (number < 10)
    {
        cout << "number < 10" << endl;
    }
    else    
    {
        cout << "number = 10" << endl;
    }

    return 0;
}
