#include<iostream>
#include<string>

using namespace std;
struct Student 
{
    int code;
    float avarage;
    string firstName;
    string lastName;

};
void getstudentdata(Student* student, size_t count);
void printstudentdata(Student* student, size_t count);
float  getStudentsAvarage(Student* student, size_t count);
int showMenu();


int main()
{
     int count;
    Student* students;
    system("cls");
    cout << "Enter The number of students:"<< endl;
    cin >> count;
    students = new Student[count];
    getstudentdata(students, count);
    printstudentdata(students, count);
    int avarage =getStudentsAvarage(students, count);
    cout << "The avarage is:" <<  avarage;

    
        
  /* int menu ;
    while(true)
    {
        
        menu=showMenu();
        if(menu == 1)
        {
           getstudentdata();
        }
        else if (menu == 2)
        {
            printstudentdata();

        }
        else if (menu == 3)
        {
            break;
        }*/
          
            
   

    delete[]students;
        
}
 
void getstudentdata(Student* student, size_t count)
{
    for (int index = 0; index < count; index++)
 { 
    cout << "Enter student ("<< index +1 << ")" <<  "code:";
    cin >> student[index].code;
    cout << "Enter student ("<< index +1 << ")" <<  "firstname:";
    cin >> student[index].firstName;
    cout << "Enter student ("<< index +1 << ")" <<  "lastname:";
    cin >> student[index].lastName;
    cout << "Enter student ("<< index +1 << ")" <<  "avarage:";
    cin >> student[index].avarage;
    cout << endl;
  }
}
void printstudentdata(Student* student, size_t count)
{
    for (int index = 0; index < count; index++)
    {
        cout << "****" << "student(" <<index+1 <<  ")" << "****" << endl;
       cout << "code :" << student[index].code << endl;
       cout << "firstname :" << student[index].firstName << endl;
       cout << "lastname :" << student[index].lastName << endl;
       cout << "avarage :" << student[index].avarage << endl;
       cout << endl;

    }
}
float  getStudentsAvarage(Student* student, size_t count)
{
    float sum = 0;
    for(int index = 0; index< count; index++)
    {
        sum+=student[index].avarage;
    }
    return (float) sum/count;
}
/* int showMenu()
{
    int result ;
    cout << "Program Menu" << endl;
    cout << "1. Get Students Data" << endl;
    cout << "2. print Students List" << endl;
    cout << "3. Exit" << endl;
    cout << "***********" <<endl;
    cout << "Select a menu: ";
    cin >> result;
    return result;
}*/

