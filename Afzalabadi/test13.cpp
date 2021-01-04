#include <iostream>
#include<vector>
#include <string >
#include <algorithm>
#include <list>


using namespace std;
bool search(list<string> names,string name);
int getData(string name);
 vector<string> names;
 string name;

int main ()
{
    
     int result;
     cout << "Enter name [1]:" <<endl;
     getline (cin, name);
     names.push_back(name);
    getData(name);


 while(true)
 
 {
     int index= 2;
     
     int result =getData(name);
      if (result ==0)
      {
          
        cout << "Enter name : " << endl;
        getline (cin, name);
        names.push_back(name);
          
      }
     else if(result == 1)
     {
         
     cout << "end";

 
      break;
    
     }

 }
 


}
int getData(string name)
{
     vector<string> names;
     string name1 = name;
     
    

   return name.empty();
}

 /*if ( search(names, name) )
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

}*/