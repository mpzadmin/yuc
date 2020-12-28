#include <iostream>

using namespace std;

char showMenu();
void profile();
void contacts();
void settings();
void theme();

int main()
{
    while (true)
    {
        char menu;
        menu = showMenu();
        if (menu == '1')
        {
            profile();
        }
        else if (menu == '2')
        {
            contacts();
        }
        else if (menu == '3')
        {
            settings();
        }
        else if (menu == '4')
        {
            theme();
        }
        else if (menu == '5')
        {
            break;
        }

    }

}

char showMenu()
{
    char result;
    cout << "TELEGRAM" << endl;
    cout << "1. Profile" << endl;
    cout << "2. Contacts" << endl;
    cout << "3. Settings" << endl;
    cout << "4. Theme" << endl;
    cout << "5. Exit" << endl;
    cout << endl;
    cout << "Select a menu: ";
    result = cin.get();
    return result;
}

void profile()
{
    system("cls");
    cout << "Edit name" << endl;
    cout << "Edit profile" << endl;
    cout << "Log out" << endl;
    system("pause");
}

void contacts()
{
    system("cls");
    cout << "Show the list of contacts" << endl;
    system("pause");
}

void settings()
{
    system("cls");
    cout << "Notificatins and Sounds" << endl;
    cout << "Privacy and Security" << endl;
    cout << "Data and Storage" << endl;
    cout << "Chat Settings" << endl;
    cout << "Folders" << endl;
    cout << "Devices" << endl;
    cout << "Language" << endl;
    system("pause");
}

void theme()
{
    system("cls");
    cout << "Show themes" << endl;
    system("pause");
}

