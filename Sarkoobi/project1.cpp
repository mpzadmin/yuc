#include <iostream>
#include <string>

using namespace std;

void delay(int delayApi);
int main(int argc, char const *argv[])

{
    string userText;
    cout << "please enter your text: ";
    getline(cin, userText);
    for (int i = 0; i < userText.length(); i++)
    {
        cout << userText[i];
        delay(40);
    } 
    void delay();
    return 0;
}
void delay(int delayApi)
{
    for (int i = 0; i < delayApi; i++)
    {
      for (int j = 0; j < 3000000; j++);
    }
}
