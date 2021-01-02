#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream textFile;
    string str;
    size_t size;

    textFile.open("test81.txt", ios::out);
    textFile << "Hello" << endl;
    textFile << "Welcome to the real world!" << endl;
    textFile << "MohammadMatin Ebrahimi" << endl;
    textFile << "Good luck!" << endl;
    textFile << "Good bye!" << endl;

    textFile.seekp(0, ios::end);
    size = textFile.tellp();

    textFile.close();

    textFile.open("test81.txt", ios::in);
    while (!textFile.eof())
    {
        getline(textFile, str);
        cout << str << endl;
    }

    cout << "File size: " << size << " bytes" << endl;

    textFile.close();
}