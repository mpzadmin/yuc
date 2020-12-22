#include <iostream>
#include <string>

using namespace std;

void display(char **name, int len);

int main()
{       
    char **name;

    display(name, 4);
}

void display(char **name, int len)
{
    for (int index=0; index < len; index++)
    {
        cout << name[index] << endl;
    }
}
