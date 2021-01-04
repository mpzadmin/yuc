#include <iostream>
#include <string>
#include <fstream>
using namespace std;
fstream file;
int main()
{  
    string str;
    file.open("test1.txt",ios::out|ios::app);
    file << "Hello" << endl;
    file << "Dani Orooji" << endl;  
    file.close();
    file.open("test1.txt",ios::in);
    while (getline(file, str))
        {
            cout << str << "\t";
        }
   cout << file.tellg();
   file.close();
}