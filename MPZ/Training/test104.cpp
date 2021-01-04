#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream textFile;
    string str;

    textFile.open("test104.txt", ios::out);    
    textFile << "Hello" << endl;
    textFile << "Welcome to C++" << endl;
    textFile << "Good Bye" << endl;
    textFile.close();

    textFile.open("test104.txt", ios::in);    
    /*
    while ( !textFile.eof() )
    {
        getline(textFile, str);
        cout << str << endl;
    }
    */

    while ( getline(textFile, str) )
    { 
        cout << str << endl;
    }

    textFile.close();
}