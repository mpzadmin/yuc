#include <iostream>
#include <string>

using namespace std;

void display(string test = "Welcome to C++!");  //Function declaration
//Be careful! Giving amount to variables should be done only in function declaration not in definition.

int main()
{
    //Function call
    display("Hello");
    display();       //Will run the default amount that you've defined in declaration.
    display("Fight for your goals!");
}

//Function definition
void display(string text)
{
    cout << text << endl;
}