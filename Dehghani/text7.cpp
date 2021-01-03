#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

bool myFindName(list <string> names, string name);


int main()
{
  list <string> names;

  string name;
  string favoriteName;
  int count;

  cout << "Entar count of name: ";
  cin >> count;
  for (int index = 0; index < count; index++)
  {
    cout << "enter name (" << index + 1 << "): ";
    cin >> name;
    names.push_back(name);
  }
  system("cls");

  cout << "Enter a favorite name: " << endl;
  cin >> favoriteName;


  if( myFindName(names, favoriteName) )
  {
    cout << "Found" << endl;
  }
  else 
  {
    cout << "Not Found"<<endl;
  }


  
}

bool myFindName(list <string> names, string name)
{
 list<string>::iterator it;
 it = find(names.begin(), names.end(), name);
 return(it != names.end()) ? true : false;

}