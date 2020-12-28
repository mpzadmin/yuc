#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char showMenu();
void hafez();
int main()
{
    char menu;
    while (true)
    {
        system("cls");
        menu = showMenu(); 
        if (menu == '1')
        {
            hafez();
        }
        else if (menu == '2')
        {
            break;
        }
    }
}
char showMenu() 
{
    char menu;
    cout << "Program Menu" << endl;
    cout << "1. hafez" << endl;
    cout << "2. exit" << endl;
    cout << endl;
    cout << "select a program: " << endl;
    menu = cin.get();
    return menu;
}
void hafez()
{ 
    string fal;
    int number,  minRandomNumber =1 , maxRandomNumber=495;
    cout << "lotfan niat konid sepas fatehe ekhlas bekhonid" << endl;
    cout << "bararye gereftan fal ok ra bezanid: " << endl;
    cin >> fal;
    if (fal == "ok") 
    { 
    srand((unsigned) time(0));  
     number = minRandomNumber + (rand() % (maxRandomNumber - minRandomNumber)) + 1;
     cout << " shomareye ghazal: " << number << endl;
     system("pause");
    }
    if (fal != "ok" )
    {
        cout << "you don't write ok " << endl;
        system("pause");
    }       
    
}