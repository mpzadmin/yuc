#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Student
{
    int code;
    string name;    
    float average;
};

const string fileName = "students.dat";
fstream file;


int main()
{
    Student student;
    list<Student> students;
    list<Student>::iterator it;      

    student.code = 101;
    student.name = "Masoud";
    student.average = 18;
    students.push_back(student);

    student.code = 102;
    student.name = "Omid";
    student.average = 19;
    students.push_back(student);

    student.code = 103;
    student.name = "Arman";
    student.average = 18.75;
    students.push_back(student);

    file.open(fileName, ios::out | ios::binary | ios::app);
    for (int index=0; index<students.size(); index++)
    {
        it = students.begin();
        advance(it, index);
        student = *it;
        file.write((char *) &student, sizeof(student));
    }
    file.close();

    students.clear();

    file.open(fileName, ios::in | ios::binary);
    while ( file.read((char *) &student, sizeof(student)) )
    {
        //cout << student.code << " : " << student.name << " : " << student.average << endl;
        students.push_back(student);
    }
    file.close();

    cout << "---------------------------------------------------" << endl;
    //cout << "List size: " << students.size() << endl << endl;
    for (Student s : students)
    {
        cout << s.code << " : " << s.name << " : " << s.average << endl;
    } 
}