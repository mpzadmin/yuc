/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

// External Libraries
#include <iostream>
#include <string>

// Namespaces
using namespace std;

// Constants
const string str1 = "Hello World!";
const int key1 = 16184;
const string str2 = "This is C++...";
const int key2 = 5386358;
const string str3 = "But I prefer Kotlin!";
const int key3 = 212;

// Function Declarations
void printResult(int key, string original, string encode1, string encode2);
string encode(string text, int key);
void clearConsole();

// Program's Entry Point
int main()
{
    string encode1, encode2, encode3, encodeTwice1, encodeTwice2, encodeTwice3;

    encode1 = encode(str1, key1);
    encode2 = encode(str2, key2);
    encode3 = encode(str3, key3);
    encodeTwice1 = encode(encode1, key1);
    encodeTwice2 = encode(encode2, key2);
    encodeTwice3 = encode(encode3, key3);

    clearConsole();

    printResult(key1, str1, encode1, encodeTwice1);
    printResult(key2, str2, encode2, encodeTwice2);
    printResult(key3, str3, encode3, encodeTwice3);
}

// Encode the text with a key, Return the encoded string
string encode(string text, int key)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] ^= key;
    }
    
    return text;
}

// Print the test result in a specific format
void printResult(int key, string original, string encode1, string encode2)
{
    cout << "Test using {key = " << key << "}: " << endl << "\tOriginal: " << original << endl << "\tEncode Once: " << encode1 << endl << "\tEncode Twice: " << encode2 << endl;
}

// Clear the console (on any OS)
void clearConsole()
{ 
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
