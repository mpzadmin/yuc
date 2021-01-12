#include<iostream>
#include<string>
#include<list>

using namespace std;

struct library
{
    float price;
    string name;
  
};
int main()
{
    int count;
    library lib;
    list<library> lst;
    list<library>::iterator itr;
     list<library>::iterator it;
    itr=lst.begin();



    cout<<"Enter number book";
    cin>> count;
    cin.ignore();
    for(int index=1; index<=count; index++)
    {
          cout<<"Enter student "<<index<<".price : ";
        cin>>lib.price;
        
        cout<<"Enter student "<<index<<".name : ";
         cin.ignore();
        getline(cin,lib.name);
         lst.push_back(lib); 
       
    }
    float mrx;
    string str;
    for(itr; itr!=lst.end(); itr++)
    {
        for(it=itr++; it!= lst.end(); it++)
        {
            if((*it). price>(*itr).price)
            {
               mrx=(*itr).price;
               (*itr).price=(*it).price;
               (*it).price=mrx;
               str=(*itr).name;
               (*itr).name=(*it).name;
               (*it).name=str;

            }
        }
    }
    cout<<lst.size()<<endl;
    for(auto index: lst)
    {
        cout<<index.name<<"      "<<index.price<<endl;
    }
   
    int sum=0;
     itr=lst.begin();
    for(auto counter: lst)
    {
        sum+=(*itr).price;   
    }
    cout<<sum<<endl;

}