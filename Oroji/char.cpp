#include <iostream>
#include <string>
using namespace std;
void delay();
int main() {
    string name;
    cout << "enter a character" << endl;
    cin >> name ;
    for(int i=0 ; i <= name.length() ; i++ )
    {
        cout << name[i] ;
        delay();
    }
}
   void delay()
     { 
       for (int index=0 ; index<= 90000000 ; index++ );
     }
    