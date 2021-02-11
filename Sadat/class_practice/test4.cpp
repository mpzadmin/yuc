#include <iostream>

using namespace std;

int main()
{
    enum Color : bool {Red = true, Green = false};
    Color color;
    color = Green;
    cout << color;
}