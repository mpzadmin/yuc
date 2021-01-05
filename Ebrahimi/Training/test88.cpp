#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

fstream file;

struct Student
{
    int code;
    string name;
    float average;
};

typedef list<Student>::iterator listStudentIt;

const string fileName = "test88.dat";
int main()
{
    Student student;
    list<Student> students;
    size_t count;
    int tempCode;
    string tempName;
    float tempAverage;

    cout << "Enter count of students: ";
    cin >> count;

    for (int index = 1; index <= count; index++)
    {
        cout << "*** Student (" << index << ") ***" << endl;

        cout << "Code: ";
        cin >> tempCode;
        student.code = tempCode;

        cin.ignore();
        cout << "Name: ";
        getline(cin, tempName);
        student.name = tempName;

        cout << "Average: ";
        cin >> tempAverage;
        student.average = tempAverage;

        students.push_back(student);
    }

    file.open(fileName, ios::out | ios::binary);
    for (listStudentIt it = students.begin(); it != students.end(); it++)
    {
        student = *it;
        file.write((char *) &student, sizeof(student));
        if (file.fail() == 1)
        {
            perror("Error in putting data to the file!");
        }
    }
    file.close();

    students.clear();

    file.open(fileName, ios::in | ios::binary);
    while ( file.read((char *) &student, sizeof(student)) )
    {
        if (file.fail() == 1)
        {
            cerr << "Error in taking data of the file!";
        }

        students.push_back(student);
    }
    file.close();

    for (Student stu : students)
    {
        cout << stu.code << " : " << stu.name << " : " << stu.average << endl;
    } 
}