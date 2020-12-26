#include <iostream>
#include <string>

using namespace std;
int main()
{
     string name = "Hossein";
    string* ptr = &name;

    cout << name << endl;
    cout << *ptr << endl;

    cout << name[0] << "\t" << name[1] << endl;
    cout << (*ptr)[0] << "\t" << (*ptr)[1] << endl;
}
