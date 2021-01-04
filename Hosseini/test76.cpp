#include <iostream>
#include <string>

using namespace std;

void display(string* name, int length);

int main()
{
    string namePtr = "Ali", namePtr2 = "Erfan";
    
    display(&namePtr, namePtr.length());
    cout << endl;
    display(&namePtr2, namePtr2.length());

}

void display(string* name, int length)
{
    for (int index = 0; index < length; index++)
    {
        cout << (*name)[index] << endl;
    }
}