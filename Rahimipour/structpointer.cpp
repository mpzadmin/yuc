#include <iostream>
#include <string>

using namespace std;

struct Student
{
    int code;
    float average;
    string name;
    string lastName;
};

void getStudentsData(Student students[], size_t len);
void printStudentsData(Student students[], size_t len);
float average(Student students[], size_t len);

int main()
{
    Student* students;
    int studentsCount;
    system("cls");

    cout << "Enter count of students: ";
    cin >> studentsCount;

    Student* students = new int [studentsCount];

    getStudentsData(students, studentsCount);
    system("pause");
    system("cls");
    printStudentsData(students, studentsCount);
    cout << endl;
    cout << "The average of the class is: " << average(students, studentsCount);
}

void getStudentsData(Student students[], size_t len)
{
    for (int index = 0; index < len; index++)
    {
        cout << "Enter student(" << (index + 1) << ") code: ";
        cin >> students[index].code;
        cout <<"Enter students(" << (index + 1) << ") name: ";
        cin >> students[index].name;
        cout << "Enter students(" << (index + 1) << ") lastname: ";
        cin >> students[index].lastName;
        cout << "Enter students(" << (index + 1) << ") grade: ";
        cin >> students[index].average;
        cout << endl;
    }
}

void printStudentsData(Student students[], size_t len)
{
    for (int index = 0; index < len; index++)
    {
        cout << " student (" << (index + 1) << ") code: " << students[index].code << endl;
        cout << " student (" << (index + 1) << ") name: " << students[index].name << endl;
        cout << " student (" << (index + 1) << ") lastname: " << students[index].lastName << endl;
        cout << " student (" << (index + 1) << ") grade: " << students[index].average << endl;
        cout << endl;
    }
}

float average(Student students[], size_t len)
{
    float sum = 0;
    float average;
    for (int index  = 0; index < len; index++)
    {
        sum += students[index].average;
    }
    average = (sum / len);
    return average;
}