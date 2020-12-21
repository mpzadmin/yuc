#include <iostream>

using namespace std;

void display(char name[]);
void display2(char *str);

int main()
{
    char name[] = "Masoud";
    display(name);
    display2(name);
}

void display(char str[])
{
    cout << str << endl;
}

void display2(char *str)
{
    cout << str << endl;
}