#include <iostream>

using namespace std;

enum Color {Yellow, Green, White, Red};
enum Direction : char {Front = 'F', Back = 'B', Left = 'L', Right = 'R'};
enum Food {Pizza = 1, Kebab, Chicken};

int main()
{
    Color color = Yellow;
    Direction direction = Front;
    Food food = Pizza;

    cout << color << endl;
    cout << direction << "\t" << (char) direction << endl;
    cout << food << endl;
}