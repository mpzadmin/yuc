#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int number = 2;

    switch (number)
    {
        case 1:
            cout << "1" << endl;
            break;            
        case 2:
        case 3:
            cout << "2 & 3" << endl;
            break;
        default:
            cout << "Others" << endl;
    }
    return 0;
}
