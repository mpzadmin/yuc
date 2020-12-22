#include <iostream>
#include <string>

using namespace std;

void display(char** name, int len);

int main()
{       
    char** name;
    name[0] = (char *) "Masoud";
    name[1] = (char *) "Ali";
    name[2] = (char *) "Reza";
    name[3] = (char *) "Mehdi";

    display(name, 4);
}

void display(char** name, int len)
{
    for (int index=0; index < len; index++)
    {
        cout << name[index] << endl;
    }
}
