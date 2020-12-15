#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main()
{
    string name;
    unsigned char key;      // 1 byte (0 ~ 255)
    
    #ifdef _WIN32
    system("cls");    
    #else
    system("clear");
    #endif

    cout << "Enter a name: ";
    getline(cin, name);

    cout << "Enter a key (1~255) for encryption: ";
    cin >> key;

    if ((key < 1) || (key > 255))
    {
        cout << "You should enter a key between 1 and 255!";
        return 0;
    }

    for(int index = 0; index < name.length(); index++)
    {
        name[index] = name[index] ^ key;
    }

    cout << "The encrypted name is: " << name << endl;
    
    system("pause");

    for(int index = 0; index < name.length(); index++)
    {
        name[index] = name[index] ^ key;
    }

    cout << "The original name is: " << name << endl;

    
}