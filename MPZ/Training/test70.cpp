#include <iostream>

using namespace std;

int main()
{
    char name[10] = {'M', 'P', 'Z', '\0'};
    cout << name << endl;

    char name2[] = {'M', 'P', 'Z', '\0'};
    cout << name2 << endl;

    char *name3 = name2;
    

    cout << name3 << endl;

}
