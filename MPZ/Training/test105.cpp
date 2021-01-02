#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream textFile;
    string str;

    textFile.open("test104.txt", ios::in);
    if ( !textFile.is_open() )
    {
        cerr << "Error in opening file" << endl;
        return 0;
    }

    textFile.seekg(0, ios::end);
    cout << "File size: " << textFile.tellg() << " bytes" << endl << endl;

    
    textFile.seekg(0, ios::beg);
    while ( getline(textFile, str) )
    { 
        cout << str << endl;
    }

    textFile.close();
}