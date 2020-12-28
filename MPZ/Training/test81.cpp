#include <iostream>

using namespace std;

enum Color {Blue, Green, Red, White};
enum Status {Studying, Suspend, Graduated};

int main()
{
    Color color;
    Status status;
    color = Color::Green;

    cout << color << endl;

    status = Status::Graduated;
    cout << status << endl;
}
