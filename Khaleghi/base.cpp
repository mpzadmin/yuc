// By: Ali Khaleqi Yekta

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    clearConsole();


}

void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
