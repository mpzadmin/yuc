#include <iostream>
#include <fstream>


using namespace std;
size_t find(string file, string name);

fstream textfile;


int main()
{
    string fileName, name;
    cout << "Enter your file name:";
    cin >> fileName;
    cout << "Enter your name :";
    getline(cin,name);
    


}

size_t find(string fileName, string name)
{
    string name1;
    size_t count = 0;
    textfile.open(fileName,ios::in);
    while(getline(textfile, name))
    {
        if (name1 == name) count++;
    }
    textfile.close();
    return count;

    
}