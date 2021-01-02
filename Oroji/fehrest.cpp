#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
void search(list<string> names, string jostojo);
int main()
{   list<string> names;
    
    string name, jostojo, f;
    int tedad;
    cout << "enter tedad names: " << endl;
    cin >> tedad;
    for (int i=0 ; i<tedad ; i++)
    {
        cout << " enter name ("<< i+1 <<"): "<< endl;
        cin >> name; 
        names.push_back(name);
    }
    system("cls");
    cout << "enter a name to find: " << endl;
    cin >> jostojo;
    search(names, jostojo);
}
void search(list<string> names, string jostojo)
{
    list<string>:: iterator it;
    it= find(names.begin(),names.end(), jostojo); 
    if (* it==jostojo)
    {
        cout<< "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
     
}
