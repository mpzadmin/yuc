#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream call;

    call.open("seektell.txt", ios::out);

    cout << "Hello" << endl;
    seekp(0, ios::beg);

    call.close();
}