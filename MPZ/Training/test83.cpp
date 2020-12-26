#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int code;
    string name;
    string lastName;
    float average;
}; 

int main()
{
    Student student;

    student.code = 1;
    student.name = "Omid";
    student.lastName = "PourZahmatkesh";
    student.average = 18.5;

    cout << student.name + ' ' + student.lastName << endl;
}