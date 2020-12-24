#include <iostream>
#include <string>

using namespace std;

void display(string* ptr, size_t len);

int main(int argc, const char** argv)
{
  string name = "Arash";
  display(&name, name.length());

}



void display(string* ptr, size_t len)
{
    for (int index = 0; index < len; index++)
    {
        cout << (*ptr)[index] << endl;
    }


}