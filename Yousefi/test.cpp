#include <iostream>
#include <string>

using namespace std;

void delay(int delayvalue = 40);

int main()
{
    string text = "wellcome to c++";
    for (int index = 0; index < text.length(); index++)
    {
        cout << text[index];
        delay();
    }
   
}
 void delay(int delayvalue)
    {
        for (int index = 0; index < delayvalue; index++)
        {
           for(int counter=0; counter < 5000000; counter++);
        }
        
    }