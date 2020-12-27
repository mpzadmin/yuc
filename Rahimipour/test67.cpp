#include <iostream>
#include <string>
#include <iomanip>
    
using namespace std;
enum Color {Blue, Green, Red, White}; 
enum Status {Studying, Suspend, Greduated};
int main()
    
{
    Color color;
    color = Color::Green;

    cout << color << endl;

    Status status;
    status = Status::Studying;
    cout << status;
}