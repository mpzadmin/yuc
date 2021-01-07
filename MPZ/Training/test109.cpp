#include <iostream>

using namespace std;

int main()
{
    if (remove("test104.txt") != 0)
    {
        perror("Error deleting file!"); 
    } 
    else 
    {
        puts("File successfully deleted");
    }
}