#include <iostream>
#include <string>

using namespace std;

void reverseString(string* texts, int count);

int main()
{
    string* texts;
    int count;

    system("cls");
    cout << "Enter count of texts: ";
    cin >> count;

    texts = new string[count];
    for (int index = 0; index < count; index++)
    {
        cout << "Enter text(" << index+1 << "): ";
        cin >> texts[index];
    }

    reverseString(texts, count);
    delete[] texts;  // Making the storage free
}

void reverseString(string* texts, int count)
{
    for (int index = count-1; index >= 0; index--)
    {
        cout << texts[index] << "\t";
    }
    cout << endl;
}