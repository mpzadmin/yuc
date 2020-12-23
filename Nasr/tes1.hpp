#include<iostream>
#include<string>
#ifdef _WIN32
#include<iostream>
#else
#include<unistd.h>
using namespace std;
#endif
using namespace std;
void display(string str)
{
    cout << str;
}

void display(string str, bool newLine)
{
    display(str);
    if (newLine)
    {
        cout << endl;
    }
}




