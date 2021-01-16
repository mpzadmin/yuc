#include <iostream>
#include <string>

using namespace std;

int findString(string mainStr, string subStr);
int findString2(string mainStr, string subStr);

int main()
{
    cout << findString("Masoud", "sou") << endl;
    cout << findString2("Masoud", "sou") << endl;

    cout << findString("Masoud", "abc") << endl;
    cout << findString2("Masoud", "abc") << endl;
}

int findString(string mainStr, string subStr)
{
    int index;
    index = mainStr.find(subStr);
    return (index != string::npos) ? index : -1;
}

int findString2(string mainStr, string subStr)
{    
    int mainStrIndex = 0, i = 0, j = 0;
    bool found = false;
    while (mainStrIndex < mainStr.length())
    {
        i = mainStrIndex;
        j = 0;
        found = true;
        while ((i < mainStr.length()) && (j < subStr.length()))
        {
            if (mainStr[i] != subStr[j])
            {
                found = false;
                break;
            }
            i++;
            j++;
        }
        if (found)
        {
            return mainStrIndex;
        }
        mainStrIndex++;
    }    
    return -1; 
}