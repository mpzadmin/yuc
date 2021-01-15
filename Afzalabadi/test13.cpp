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
         
     cout << "Enter name  :" << endl;
     getline (cin, name);
     names.push_back(name);
    for (; ;)
    {
       
        
        if(!(name.empty()))
        {
            
        cout << "Enter name  :" << endl;
        getline (cin, name);
        names.push_back(name);
        

        }
        
        else
        {
           for(int index =0; index < names.size(); index++)
             {
                 int counter = 0;
                 string repetedName = names[index];
                 for(int i=0; i< names.size();i++)
                 {
                     if(repetedName == names[i])
                     {
                        counter++;
                     }
                    
                     cout <<"The "  << repetedName << "repeted" << counter << "times" <<endl;

                 }
             }

            cout << "end";
            break;
        }
 
    }

}