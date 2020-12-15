#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Masoud Pour Zahmatkesh";
    cout << name.at(3) << endl;
    cout << name.substr(7, 4) << endl;
    cout << name << endl;
    cout << name.find("b") << endl;
    if ( name.find("b") == name.npos ) 
    {
        cout << "Not Found!";    
    }
    cout << name.npos << endl;
}