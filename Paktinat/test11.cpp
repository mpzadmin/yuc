#include <iostream>
 
using namespace std;

string encode(int key, string str);

int main()
{
    string str, str1;
    int key;
    cout << "enter a string : ";
    getline(cin, str); 
    cout << "enter a key: ";
    cin >> key;
    cout << encode(key, str);
}

string encode (int key, string str)
{
  for (int i=0; i < str.length(); i++)
  {
    str[i] = str[i]^key; 
  }
  return str;
}
