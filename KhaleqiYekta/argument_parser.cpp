/*
 *  @brief Command-line Argument Parser
 * 
 *  @author YektaDev [Ali Khaleqi Yekta]
 *  Website: Yekta.Dev
 *  Email: Me@Yekta.Dev
 */

/** External Libraries **/
#include <iostream>
#include <string>
#include "console.hpp"

/** Namespaces **/
using namespace std;

/** Constants **/
const string errorNoArg = "No Arguments Found!";

// Program's Entry Point
int main(int argc, char const *argv[])
{
    clearConsole();

    if (argc <= 1)
    {
        cout << errorNoArg << endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        printLine("Argument " + to_string(i) + " is: " + argv[i]);
    }
    
    return 0;
}
