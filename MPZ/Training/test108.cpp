#include <iostream>
#include "test108.hpp"

using namespace std;
using namespace mpz;

int main()
{
    fileName = "test.txt";    
    openFile();

    find(100);

    closeFile();
}