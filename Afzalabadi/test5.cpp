#include <iostream>
#include <string>

using namespace std;
void display(string *name,size_t length  );

int main()
{
    string name = "Ali";
    display(&name, name.length());

}
 void display(string *name,size_t  length  )
{
    for(int index = 0; index < length; index++)
    {
        cout << (*name) [index] << endl ;
    }
    
}