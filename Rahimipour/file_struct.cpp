#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream file;

struct bNazanin
{
    int number;
    string name;
    float average;
};

int main()
{
    bNazanin students;
    students.name = "Ahad";
    students.number = 9929093;
    students.average = 20;

    remove("file_struct.dat");
    file.open("file_struct.dat", ios::out | ios::binary | ios::app);
    file.write((char *) &students, sizeof(students));
    file.close();

    students.number = 19;

    file.open("file_struct.dat", ios::in | ios::binary);
    while (file.read((char *) &students, sizeof(students)))
    {
        cout << students.name << ":" << students.number << ":";
    }
    file.close();
}