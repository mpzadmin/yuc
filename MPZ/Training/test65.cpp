#include <iostream>
#include <string>

using namespace std;

int main()
{
    string food1 = "Pizza";
    string food2 = "Beef";
    string food3 = "Chicken";

    string &meal = food3;    
    cout << meal << endl;
}