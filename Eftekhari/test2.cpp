#include <iostream>
#include <string>
using namespace std;

void display(string str, bool newLine);
void display(string str);

int main(int argc, char const *argv[])
{
    display("EFTEKHARI", true);
    return 0;
}
void display(string str)
{
    cout << str ;
}
void display(string str,bool newLine)
{
    cout <<(str) ;
    if(newLine)
    cout <<endl;
}

