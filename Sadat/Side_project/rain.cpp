#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <windows.h>

using namespace std;

const int worldHeight = 35;
const int worldWidth = 120;
const int dropCount = 90;
const int updateCount = 500;
const int dropOffset = 10;
const int dropSpeedDifrence = 2;

class Drop 
{
    public: string type;
    public: int x;
    public: int y;
    
    public: void fall()
    {
        y += (rand() % (dropSpeedDifrence + 1)) + 1;
        if (y >= worldHeight)
        {
            y = -(rand() % dropOffset);
            type = (rand() % 2 == 1) ? "|" : "|";
        }
    }
};

int main()
{
    Drop drop[dropCount];
    string lineContent[worldHeight];
    srand(123456789);
    
    for (int i = 0; i < dropCount; i++)
    {
        drop[i].type = (rand() % 2 == 1) ? "|" : "|";
        drop[i].x = rand() % worldWidth;
        drop[i].y = rand() % worldHeight;
    }
    for (int i = 0; i < updateCount; i++)
    {
        system("cls");
        for (int a = 0; a < worldHeight; a++)
        {
            lineContent[a] = "";
            lineContent[a].insert(0, worldWidth, ' ');
        }
        for (int j = 0; j < dropCount; j++)
        {
            if (drop[j].y >= 0)
            {
                lineContent[drop[j].y].replace(drop[j].x, 1, drop[j].type);
            }
        }
        for (int l = 0; l < worldHeight; l++)
        {
            cout << lineContent[l] << endl;
        }
        for (int d = 0; d < dropCount; d++)
        {
            drop[d].fall();
        }
        cout << setfill('_') << setw(worldWidth) << "" << endl;
    }  
}