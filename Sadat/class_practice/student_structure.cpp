#include <iostream>

using namespace std;

struct Student
{
    string firstName;
    string lastName;
    float average;
};

void getStudentData(Student* student, size_t length);
void showList(Student* student, size_t length);
float calculateAverage(Student* student, size_t length);

int main()
{
    Student* student;
    int studentCount;
    float averagePoint;

    cout << "Enter student's count: ";
    cin >> studentCount;
    student = new Student[studentCount];
    getStudentData(student, studentCount);
    showList(student, studentCount);
    averagePoint = calculateAverage(student, studentCount);
    cout << "Your students average point is: " << averagePoint;
    delete []student;
}

void showList(Student* student, size_t length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Student " + to_string(i) + " first name: " + student[i].firstName;
        cout << " last name: " + student[i].lastName;
        cout << " average point: " + to_string(student[i].average) << endl;
    }
}

void getStudentData(Student* student, size_t length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Enter first name, last name, average point of student " + to_string(i + 1) + ": ";
        cin >> student[i].firstName >> student[i].lastName >> student[i].average;
    }
}

float calculateAverage(Student* student, size_t length)
{
    float average = 0;
    for (int i = 0; i < length; i++)
    {
        average += student[i].average;
    }
    average /= length;
    return average;
}