#include <iostream>

using namespace std;

struct Student
{
    int code;
    string firstName;
    string lastName;
    float average;
    string favoriteColor;
    string favoriteFood;
    string favoriteLesson;
};

int main()
{
    Student* student;
    student = new Student [2];

    student[0].code = 1;
    student[0].firstName = "MohammadMatin";
    student[0].lastName = "Ebrahimi";
    student[0].favoriteFood = "Pizza";
    student[0].favoriteColor = "Yellow";

    student[1].code = 2;
    student[1].firstName = "Mahdi";
    student[1].lastName = "Ebrahimi";
    student[1].favoriteFood = "Kebab";

    cout << student[0].code << "\t" << student[0].firstName + ' ' + student[0].lastName << endl;
    cout << student[0].favoriteColor << "\t" << student[0].favoriteFood << endl;
    cout << endl;
    cout << student[1].code << "\t" << student[1].firstName + ' ' + student[1].lastName << endl;
    cout << student[1].favoriteColor << "\t" << student[1].favoriteFood << endl;
}