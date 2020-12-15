#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string name = "Masoud";
    string lastName = "PourZahmatkesh";

    cout << "Hello" << " " << name << " " << lastName << endl;
    cout << "Hello " + name + " " + lastName << endl;
    return 0;    
}
