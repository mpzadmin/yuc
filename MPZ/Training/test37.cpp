#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Masoud";
    string lastName = "Pour Zahmatkesh";
    string fullName;
    
    fullName.clear();
    fullName.append(name);
    fullName.append(" ");
    fullName.append(lastName);
    
    cout << fullName << endl;
    
    /*
    name.clear(); // name = "";
    cout << name.append("OK") << endl;
    cout << name << endl;

    name.append(" GoodBye");
    cout << name << endl;
    */
}