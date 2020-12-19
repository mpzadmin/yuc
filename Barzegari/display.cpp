#include <iostream>

using namespace std;

void display (string str);
void display (string str, bool newLine);

int main(int argc, char const *argv[])
{
    display("Hello", true);
    display("Word", true);
    display("Bye");
}

void display (string str)
{
    cout << str;
}

void display (string str, bool newLine)
{
    display(str);
    if(newLine)
        cout << endl;
}