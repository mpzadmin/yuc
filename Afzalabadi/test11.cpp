#include <iostream>
#include <string >
#include <algorithm>
#include <list>


using namespace std;
bool search(list<string> names,string name);

int main ()
{
 string name;
 list<string> names;
 

 names.push_back("ali");
 names.push_back("reza");
 names.push_back("amir");
 names.push_front("hossien");
 cout << "Enter a name: ";
 getline(cin,name);

 if ( search(names, name) )
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND";
    }





}
bool search(list<string> names,string name)
{
    list <string > ::iterator it;
    it = find(names.begin(),names.end(),name);
    return (it != names.end()) ?true :false;

}