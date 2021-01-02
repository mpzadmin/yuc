#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void search(vector<string> names, string jostojo);
int main()
{   vector<string> names;
    
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
void search(vector<string> names, string jostojo)
{
    vector<string>:: iterator it;
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
