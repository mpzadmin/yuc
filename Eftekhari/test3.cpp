#include <iostream>
using namespace std ;

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        cout << "You havent entered parameter" ;
        return 0 ;
    }
    cout << "welcome" << argv[1] << endl ;
    
    
    return 0;
}
