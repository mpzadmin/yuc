#include <iostream>
#include <string>

using namespace std;

string encode(string str, unsigned char key);
string decode(string str, unsigned char key);

int main()
{
    string name;
    unsigned char key = 222;
    cout << "Enter a string: ";
    getline(cin, name);    
    name = encode(name, key);
    cout << "Encoded string: (" << name << ")" << endl;
    name = decode(name, key); 
    cout << "Decoded string: (" << name << ")" << endl;
}

string encode(string str, unsigned char key)
{
    for (int index=0; index<str.length(); index++)
    {
        str[index] += 2;
    }
    for (int index=0; index<str.length(); index++)
    {
        str[index] = str[index] ^ key;
        key = str[index];
    }
    return str;
}

string decode(string str, unsigned char key)
{
    unsigned currentKey;
    for (int index=str.length()-1; index>=0; index--)
    {
        index>0 ? currentKey = str[index-1] : currentKey = key;
        str[index] = str[index] ^ currentKey;
    }
    for (int index=0; index<str.length(); index++)
    {
        str[index] -= 2;
    }
    return str;
}