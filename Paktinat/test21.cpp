#include <iostream>
#include <windows.h>

using namespace std;

void setcolor ( int number, string sentence);

int main()
{
 string sentence;
 cout << " Enter a sentence : ";
 getline (cin ,sentence);
 for (int i; i <= sentence.length(); i++)
  {
    if (sentence[i] = ' ' )
    {
      cout << sentence[i+1].setcolor();
    }
  }
}

void setcolor (int number, string sentence)
{
  for (int i=1; i <= 255; i++)
  {
      cout << sentence.setcolor(i);
  }   
}