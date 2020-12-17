#include <iostream>
#include <string>

using namespace std;
void delay(int delaynumber = 100000000);

int main()
{
    string charector ;
    cout << "Enter your charector :";
    getline(cin, charector);
    for( int index = 0; index < charector.length(); index++   )
    {
        cout << charector[index];
        delay();
    }

}
void delay(int delaynumber  )
{
    for( int counter=1; counter<= delaynumber; counter++ );
}



