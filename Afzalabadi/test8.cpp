#include <iostream>

using namespace std;
int showMenu();

int main()
{
    int menu ;
    while(true)
    {
        
        menu=showMenu();
        if(menu == 1)
        {
           cout << " getstudentdata();";
        }
        else if (menu == 2)
        {
            cout << "printstudentdata();";

        }
        else if (menu == 3)
        {
            break;
            

        }

    }
}



int showMenu()
{
    int  result ;
    cout << "Program Menu" << endl;
    cout << "1. Get Students Data" << endl;
    cout << "2. print Students List" << endl;
    cout << "3. Exit" << endl;
    cout << "***********" <<endl;
    cout << "Select a menu: ";
    cin >> result;
    return result;

      
}