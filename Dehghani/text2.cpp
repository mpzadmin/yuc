#include <iostream>
#include <iomanip>

using namespace std;

void display(string str);
void display(string str, bool newLine);

int main()
{
    display("Hello", true);
    display("welcome");
    display("Bye",true);


}
void display (string str)
{
    cout << str;
}

void display(string str, bool newLine)
{  
  display (str);
  cout << str;
  if(newLine)
  {
      cout << endl;
  }
}