#include <iostream>
#include <string>

using namespace std;

void display (string* str, size_t len);

int main(int argc, char const *argv[])
{
    string s = "Hello";
    display(&s, s.length());
}

void display (string* str, size_t len)
{
    for(int i = 0; i < len; i++)
    {
        cout << (*str)[i] << endl;
    }
}