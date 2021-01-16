/*
    Encryption & Decryption App
    By: Ali Khaleqi Yekta
*/

#include <iostream>
#include <string>

using namespace std;

const int initialKey = 222;

int main() {
    string userStr;
    int lastKey = initialKey;

    system("cls");

    cout << "Enter a text: ";
    getline(cin, userStr);

    // Encryption
    for (int i = 0; i < userStr.length(); ++i)
    {
        // Character Replacement
        userStr[i] = userStr[i] + 2;

        // XOR Operation
        userStr[i] ^= lastKey;

        // The New Key
        lastKey = userStr[i];
    }

    cout << "Encrypted Value: " << userStr << endl;

    // Decryption
    for (int i = userStr.length() - 1; i >= 0; --i)
    {
        // The New Key
        if (i == 0)
        {
            lastKey = initialKey;
        }
        else
        {
            lastKey = userStr[i-1];
        }

        // XOR Operation
        userStr[i] ^= lastKey;

        // Character Replacement
        userStr[i] = userStr[i] - 2;
    }

    cout << "Decrypted Value: " << userStr << endl;

    return 0;
}