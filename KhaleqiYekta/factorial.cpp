/*
 * Copyright © 2021 Ali Khaleqi Yekta, All Rights Reserved.
 *
 * Author: Ali Khaleqi Yekta [YektaDev]
 * Website: https://Yekta.Dev
 * Email: Me@Yekta.Dev
 */

// External Libraries
#include <iostream>

// Namespaces
using namespace std;

// Function Declarations
long int factorial(unsigned number);
void clearConsole();

// Program's Entry Point
int main()
{
    clearConsole();

    // Test the function
    cout << "The factorial of 0 is: " << factorial(0) << endl;
    cout << "The factorial of 3 is: " << factorial(3) << endl;
    cout << "The factorial of 4 is: " << factorial(4) << endl;
    cout << "The factorial of 5 is: " << factorial(5) << endl;
    cout << "The factorial of 8 is: " << factorial(8) << endl;
    cout << "The factorial of 10 is: " << factorial(10) << endl;
    cout << "The factorial of 14 is: " << factorial(14) << endl;
}

// Return the factorial of given positive number
long int factorial(unsigned number)
{
    int result = 1;

    if (number < 0)
    {
        return -1;
    }

    for(int i = 1; i <= number; i++)
    {    
        result = result * i;
    }

    return result;
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
