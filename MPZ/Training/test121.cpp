#include <iostream>
#include <windows.h>

using namespace std;

void setColor(int color);

int main()
{
    setColor(1);
    cout << "Hello" << endl;    

    setColor(2);
    cout << "Hello" << endl;    

    setColor(4);
    cout << "Hello" << endl;    

}

void setColor(int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}