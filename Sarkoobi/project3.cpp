#include <iostream>

using namespace std;

void display(string* ptr, size_t len);
int main(int argc, char const *argv[])
{
    string name = "mojtaba";
    display(&name, name.length());
    return 0;
}

void display(string* ptr, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        cout << (*ptr)[i] << endl;
    }
}
