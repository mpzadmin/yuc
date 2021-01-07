#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    int code;
    string name;    
    float average;
};

fstream file;

int main()
{
    Student student;

    student.code = 100;
    student.name = "Masoud";
    student.average = 18;

    file.open("student.dat", ios::out | ios::binary);
    file.write((char *) &student, sizeof(student));
    file.close();

    student.code = 0;

    file.open("student.dat", ios::in | ios::binary);
    file.read((char *) &student, sizeof(student));
    file.close();

    cout << student.code << " , " << student.name << " , " << student.average;

}