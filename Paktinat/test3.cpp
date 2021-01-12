#include <iostream>
#include <string>

using namespace std;

//void display(string sentence[], string word[]);

int main()
{
    string sentence, word;
    string a = word;
    cout << "Enter a sentence : " << endl;
    getline (cin, sentence);
    cout << " Enter a word : " << endl;
    getline (cin, word);
    for (int i=0; i <= sentence.length(); i++)
    {
        if (sentence[i]==word[0])
        {
        
        }
    }
    cout << a;
}