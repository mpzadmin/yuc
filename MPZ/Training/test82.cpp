#include <iostream>

using namespace std;

enum Color {Blue = 1, Green = 2, Red = 4, White = 255};
enum Direction {Front, Back = 10, Left, Right};
enum Food : char {Pizza = 'P', Kebab = 'K', Chicken = 'C'};

void setColor(Color color);

int main()
{
    Color color;  

    color = Color::Green;
    cout << color << endl;
    setColor(Color::White);


    Direction direction = Direction::Left;
    cout << direction << endl;

    Food food = Kebab;
    cout << (char) food << endl;

}

void setColor(Color color)
{

}
