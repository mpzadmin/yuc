#include <iostream>
#include <string>
#include <fstream>
    
using namespace std;

fstream names;

int main()
{
    // Not Completed
    string name;
    int counter = 0;
    names.open("names.txt", ios::in);
   
    cout << "Enter a name that you want to be searched: ";
    getline(cin, name);

    if ("names.txt" == name)
    {
        counter += 1;
    }
   
    names.close(); 
    
}