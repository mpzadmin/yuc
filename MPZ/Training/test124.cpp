#include <iostream>
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
    Student students[100];
    Student* ptr;  

    students[0].code = 1;
    students[0].name = "Ali";
    students[0].average = 19;
    
    students[99].code = 100;
    students[99].name = "Hamid";
    students[99].average = 20;

    ptr = new Student;
    (*ptr).code = 1;
    (*ptr).name = "Reza";
    (*ptr).average = 17;     
    delete ptr;


    ptr = new Student [100];
    (*ptr).code = 1;
    (*ptr).name = 1;
    (*ptr).average = 1;

    ptr += 99;
    (*ptr).code = 100;
    (*ptr).name = "Hamid";
    (*ptr).average = 20;

    (*ptr).code = 1;
    ptr->code = 1;

    int index = 0;
    (ptr + index)->code = 10;      

    delete[] ptr;

}