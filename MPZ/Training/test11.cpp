#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string name;
    system("cls");

    cout << "Enter your name: ";
    //cin >> name;
    getline(cin, name);

    cout << "Hello " + name << endl;
    return 0;
}
