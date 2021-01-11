#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Student
{
    int code;
    string name;
    float average;
}; 

int main()
{
    int studentCount = 3;
    Student student;
    list<Student> students;

    for (int counter=0; counter<studentCount; counter++ ) {
        cout << "Enter student[" << counter+1 << "] code: ";
        cin >> student.code;
        cout << "Enter student[" << counter+1 << "] name: ";
        cin.ignore();
        getline(cin, student.name);
        cout << "Enter student[" << counter+1 << "] average: ";
        cin >> student.average;

        students.push_back(student);
    }

    system("cls");
    for (Student stu : students)
    {
        cout << stu.code << " , " << stu.name << " , " << stu.average << endl;
    }

}