#include <iostream>
#include <string>

using namespace std;
void display(string, bool);
void display(string);

int main()
{
    display("text1" , true);
    display("text2");
}

void display(string text, bool newLine)
{
    display(text);
    if (newLine) cout << endl;
}

void display(string text)
{
    cout << text;
}