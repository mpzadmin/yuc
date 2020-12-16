#include <iostream>
#include <string>

using namespace std;

void dellay(int);

int main()
{   
    string str = "Hello world";
    for (int index = 0; index <= str.length(); index++)
    {
        cout << str[index];
        dellay(30);

    }
    cout << endl;
}


void dellay(int delayvalue)
{
    for (int index = 0; index < delayvalue; index++)
    {
        for (int counter = 0; counter < 1000000; counter++);
    }
}
