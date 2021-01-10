#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

fstream file;
struct Student
{
    int number;
    float average;
    string name;
};

int main()
{
    Student student;
    list<Student> listStudents;
    list<Student>::iterator it;

    student.name = "Ahad";
    student.average = 19;
    listStudents.push_back(student);

    student.name = "Ali";
    student.average = 16;
    listStudents.push_back(student);

    student.name = "Mom";
    student.average = 19.5;
    listStudents.push_back(student);

    file.open("file_list_struct.dat", ios::out | ios::binary);
    for (int index = 0; index < listStudents.size(); index++)
    {
        it = listStudents.begin();
        advance(it,index);
        student = *it;
        file.write((char *) &student, sizeof(student));
    }
    file.close();

    file.open("file_list_struct.dat", ios::in | ios::binary);
    while ( file.read((char *) &student, sizeof(student)))
    {
        listStudents.push_back(student);
        cout << student.name << ": " << student.average << endl;
    }
    file.close();
}