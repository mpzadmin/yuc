#include <iostream>
#include <string>

using namespace std;

void display(string str, bool nextLine);
void display(string str);

int main()
{
    display("Arman", true);
    display(":)");
}
void display(string str)
{
    cout << str;
}
void display(string str, bool nextLine)
{
    display(str);
    if (nextLine)
        cout << endl;
}