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
    struct Student student;// we could not write struct here.
    student.code = 1;
    student.name = "Ahad";

    cout << student.name;

}