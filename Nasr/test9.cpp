#include <iostream>

using namespace std;

char showMenu();
void getStudentsData();
void printStudentsData();

int main()
{
    char menu;
    while(true)
    {
        system("cls");
        menu = showMenu();
        if (menu == '1')
        {
            getStudentsData();
        } 
        else if (menu == '2')
        {
            printStudentsData();
        }
        else if (menu == '3')
        {
            break;
        }
    }
}

char showMenu()
{
    char result;
    cout << "Program Menu" << endl;
    cout << "1. Get Students Data" << endl;
    cout << "2. Show Students List" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Select a menu: ";
    result = cin.get();
    return result;
}

void getStudentsData()
{
    cout << "getStudentsData" << endl;
    system("pause");           
}

void printStudentsData()
{
    cout << "printStudentsData" << endl;
    system("pause");           
}