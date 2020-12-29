#include <iostream>
#include <exception>

using namespace std;

int main()
{
    int age;

    system("cls");
    cout << "Enter your age: ";
    cin  >> age;

    try 
    {
        if (age >= 18)
        {
            cout << "Access granted, your are old enough";
        }
        else
        {
            throw (age);    
        }    
    } 
    catch(int value) 
    {
        cout << "Access denied, you musg be at least 18 years old!" << endl;
        cout << "Your age is: " << value << endl;
    }
}
