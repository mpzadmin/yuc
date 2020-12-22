#include <iostream>
#include <string>

using namespace std;

void display (string *str, int size);

int main(int argc, char const *argv[])
{
    string s = "Hello";
    string* ptr = &s; 
    display(ptr, 5);
}

void display (string *str, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << (*str)[i] << endl;
    }
}