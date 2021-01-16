#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

int main(int argc, const char** argv) 
{
     fstream file;
    file.open(argv[1], ios::in);
    string str;
    char ch='{';
    char mychar='}';
    vector<int> vec, mrx;
    
    int counter=0;
    int i=0;
   
  while(file.eof()==false)
  {
    while(getline(file, str))
    {
     counter++;
    if(str.find(ch)!=str.npos)
    {
      
        i++;
        vec.push_back(counter);
        mrx.push_back(i);
    }
    else if(str.find(mychar)!=str.npos);
    {
        
        
        mrx.erase(mrx.end()-1);
    }
    }
  
  }
  if(mrx.size()==0)
  {
      cout<<"number of block"<<i<<endl;
  }
  else
  {
      cout<<counter<<endl;
  }
  
    return 0;
}