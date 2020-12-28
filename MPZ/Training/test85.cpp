#include <iostream>
#include <string>

using namespace std;

const int maxStudents = 100;

struct Student
{
    int code;
    string name;
    string lastName;
    float average;
}; 

void getStudentData(Student students[], size_t len);
void printStudentData(Student students[], size_t len);
float getStudentsAverage(Student students[], size_t len);

int main()
{
    Student students[maxStudents];
    int studentCount;

    system("cls");

    cout << "Enter count of students: ";
    cin >> studentCount;

    getStudentData(students, studentCount);
    printStudentData(students, studentCount);
    cout << endl;
    cout << "The students average is: " << getStudentsAverage(students, studentCount) << endl;

    system("pause");   
}

void getStudentData(Student students[], size_t len)
{
    for (int index=0; index<len; index++)
    {
        cout << "Enter student(" << index+1 << ") code: ";
        cin >> students[index].code;
        cout << "Enter student(" << index+1 << ") name: ";
        cin >> students[index].name;
        cout << "Enter student(" << index+1 << ") lastname: ";
        cin >> students[index].lastName;
        cout << "Enter student(" << index+1 << ") average: ";
        cin >> students[index].average;
        cout << endl;
    }
}

void printStudentData(Student students[], size_t len)
{
    for (int index=0; index<len; index++)
    {
        cout << "*** " << "Student(" << index+1 << ")" << " ***" << endl;
        cout << "Code: " << students[index].code << endl;
        cout << "Full Name: " << students[index].name + ' ' + students[index].lastName << endl;
        cout << "Average: " << students[index].average << endl;
        cout << endl;
    }
}

float getStudentsAverage(Student students[], size_t len)
{
    float sum = 0;
    for (int index=0; index<len; index++)
    {
        sum += students[index].average;
    }
    return (float) sum/len;
}