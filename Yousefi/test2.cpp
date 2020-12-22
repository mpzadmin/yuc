#include <iostream>
#include <string>

using namespace std;

void display(string name, int number);

int main(int argc, char const *argv[])
{
    string name;
    int number;
    cout << "name is: ";
    cin >> name;
    cout << "size of name: ";
    cin >> number;


    display(name ,number);

    return 0;
}
void display(string name, int number)
{
    string* n = &name;
    for (int index=0; index < name.length(); index++)
    {
        cout << (*n)[index] << endl;
    }
    
         
    
    
   
    
}


    

