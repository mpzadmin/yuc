#include <iostream>
#include <string>

using namespace std;

void display(string* ptr,int size);

int main()
{
    string name = "hello world";

    display(&name, name.length());    
}

 void display(string* ptr,int size)
{
    for (int index=0; index<size; index++)
    {
        cout << (*ptr)[index] << endl;
    }

}

