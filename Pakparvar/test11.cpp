#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("cls");
    fstream textFile;
    string str;

    remove("test11.txt");
    
    textFile.open("test11.txt", ios::out);    
    textFile << "Hello" << endl;
    textFile << "My name is hossein" << endl;
    textFile << "Good Bye" << endl;
    textFile.close();

    textFile.open("test11.txt", ios::in);    
    

    while ( getline(textFile, str) )
    { 
        cout << str << endl;
    }

    textFile.close();
}