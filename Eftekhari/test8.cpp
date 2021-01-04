#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std ;

bool nameFind(list<string>names,string name);

int main(int argc, char const *argv[])
{
    list<string> names ;
    int count ;
    string tempName , name ;
    cout <<"Enter a count of names :";
    cin >> count ;
    for (int index = 0; index < count; index++)
    {
      cin >>tempName ;
      names.push_back(tempName);

    }
    cout<<"Enter a name for find in the list:";
    cin >> name;
    if (nameFind(names,name))
    {
        cout <<"Found"<<endl ;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    
    
    
    return 0;
}
bool nameFind(list<string>names,string name)
{
    list<string>::iterator it ;
    it = find(names.begin(),names.end(),name);
    return(it != names.end()) ? true : false ;
}