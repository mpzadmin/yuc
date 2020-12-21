#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "Ahad";
    //string *ptr = &name;

    int list[3] = {1, 2, 3};
    int *ptr = list;
    cout << list[1] << endl;
    cout << *(ptr+1) << endl;
    cout << *(list+1) << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    for (int index = 0; index < name.length(); index++)
    {
        cout << name[index] << " ";
        cout << *(ptr + index) << " ";
    }
    */
}