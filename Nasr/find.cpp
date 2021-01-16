#include<iostream>
#include<fstream>

using namespace std;

fstream file;
size_t findWord(string  , string);

int main()
{
    string fileaddres;
    string word;
    cout<<"Enter your addres file ";
    getline(cin,fileaddres);
    
    cout<<"Enter a word you want find";
    getline(cin,word);
    cout<<findWord(fileaddres,word);
 


}
size_t findWord(string File , string word)
{ 
    int count;
    file.open(File,ios::out);

    cout<<"how many data input to file";
    cin>>count;
    string data[count];

    for(int index=0; index<count; index++)
    {
        cout<<"Enter data("<<index+1<<"): ";
        cin>>data[index];
        file<<data[index]<<endl;
        
    }
    file.close();
    int counter=0;
    string name;
    file.open(File,ios::in); 
    if(!file.is_open())
    {
        cout<<"Error in open file";
    }
    
    while(getline(file,name))
    {
        if(name==word)
        {
            counter++;
        }
    }
    file.close();
    return counter;
}
