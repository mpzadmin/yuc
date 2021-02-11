#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <ctime>

using namespace std;

const int gameHeight = 16;
const int gameWidth = 30;
const int gameRatio = 2;
const int blockSize = 1;
const int loseHeight = 0;
const int frameDelay = 60000;
const int fastFallDelay = 350;
const int maxShapeSize = 4;
const int minShapeSize = 1;
string gameBoard[gameHeight][gameWidth];
bool lose = false;
bool fallingShapeExists = false;
bool fastFall = false;
int color = 0;
int groupIndex = 0;
int callIndex = 0;
int test = 0;
bool leftKey = false, rightKey = false, upKey = false, downKey = false;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void hidecursor();
void preset();
bool isFalling(int, int);
void fall();
void showBoard();
void addBlockToGroup(int, int, int, int, bool);
void moveLeft();
void moveRight();
void rotate();
void checkFullRow();
void isGameOver();

int main()
{
    int c = 0;
    int frameCount = 0;
    srand(time(0));
    preset();
    while (!lose)
    {
        if (frameCount > 500)
        {
            lose = true;
        }
        if (c % frameDelay == 0)
        {
            test = 0;
            fallingShapeExists = false;
            hidecursor();
            showBoard();
            fall();
            if (!fallingShapeExists)
            {
                checkFullRow();
                //isGameOver();
                fastFall = false;
                groupIndex++;
                addBlockToGroup(((rand() % 15) + 1), 0, rand() % gameWidth, (rand() % (maxShapeSize - minShapeSize)) + minShapeSize, true);
            }
            if (fastFall)
            {
                c = frameDelay - fastFallDelay;
            }
            else
            {
                c = 1;
            }
            frameCount++;
            //system("pause");
        }
        if ((GetKeyState(VK_LEFT) && !leftKey) || (!GetKeyState(VK_LEFT) && leftKey))
        {
            leftKey = !leftKey;
            moveLeft();
        }
        if ((GetKeyState(VK_RIGHT) && !rightKey) || (!GetKeyState(VK_RIGHT) && rightKey))
        {
            rightKey = !rightKey;
            moveRight();
        }
        if ((GetKeyState(VK_DOWN) && !downKey) || (!GetKeyState(VK_DOWN) && downKey))
        {
            downKey = !downKey;
            fastFall = true;
        }
        if ((GetKeyState(VK_UP) && !upKey) || (!GetKeyState(VK_UP) && upKey))
        {
            upKey = !upKey;
            rotate();
        }
        c++;
    }
}

void hidecursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &info);
}

void preset()
{
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            gameBoard[i][j] = "0";
        }
    }
}

bool isFalling(int row, int column)
{
    bool fallResult = true;
    //test++;
    //cout << gameBoard[row][column] << " ";
    if (row == gameHeight - 1)
    {
        return false;
    }
    if (gameBoard[row + 1][column] != "0" && gameBoard[row][column].substr(gameBoard[row][column].find('g') + 1, gameBoard[row][column].find('c') - (gameBoard[row][column].find('g') + 1)) != gameBoard[row + 1][column].substr(gameBoard[row + 1][column].find('g') + 1, gameBoard[row + 1][column].find('c') - (gameBoard[row + 1][column].find('g') + 1)))
    {
        return false;
    }
    if (gameBoard[row + 1][column] != "0" && gameBoard[row][column].substr(gameBoard[row][column].find('g') + 1, gameBoard[row][column].find('c') - (gameBoard[row][column].find('g') + 1)) == gameBoard[row + 1][column].substr(gameBoard[row + 1][column].find('g') + 1, gameBoard[row + 1][column].find('c') - (gameBoard[row + 1][column].find('g') + 1)) && gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1)) != gameBoard[row + 1][column].substr(gameBoard[row + 1][column].find('c') + 1, gameBoard[row + 1][column].length() - (gameBoard[row + 1][column].find('c') + 1)))
    {
        test = 1;
        gameBoard[row + 1][column] = gameBoard[row + 1][column].substr(0, gameBoard[row + 1][column].find('c') + 1) + gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1));
        if (!isFalling(row + 1, column))
        {
            fallResult = false;
        }
    }
    if (gameBoard[row - 1][column] != "0" && row > 0 && gameBoard[row][column].substr(gameBoard[row][column].find('g') + 1, gameBoard[row][column].find('c') - (gameBoard[row][column].find('g') + 1)) == gameBoard[row - 1][column].substr(gameBoard[row - 1][column].find('g') + 1, gameBoard[row - 1][column].find('c') - (gameBoard[row - 1][column].find('g') + 1)) && gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1)) != gameBoard[row - 1][column].substr(gameBoard[row - 1][column].find('c') + 1, gameBoard[row - 1][column].length() - (gameBoard[row - 1][column].find('c') + 1)))
    {
        test = 2;
        gameBoard[row - 1][column] = gameBoard[row - 1][column].substr(0, gameBoard[row - 1][column].find('c') + 1) + gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1));
        if (!isFalling(row - 1, column))
        {
            fallResult = false;
        }
    }
    if (gameBoard[row][column - 1] != "0" && column > 0 && gameBoard[row][column].substr(gameBoard[row][column].find('g') + 1, gameBoard[row][column].find('c') - (gameBoard[row][column].find('g') + 1)) == gameBoard[row][column - 1].substr(gameBoard[row][column - 1].find('g') + 1, gameBoard[row][column - 1].find('c') - (gameBoard[row][column - 1].find('g') + 1)) && gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1)) != gameBoard[row][column - 1].substr(gameBoard[row][column - 1].find('c') + 1, gameBoard[row][column - 1].length() - (gameBoard[row][column - 1].find('c') + 1)))
    {
        test = 3;
        gameBoard[row][column - 1] = gameBoard[row][column - 1].substr(0, gameBoard[row][column - 1].find('c') + 1) + gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1));
        if (!isFalling(row, column - 1))
        {
            fallResult = false;
        }
    }
    if (gameBoard[row][column + 1] != "0" && column < gameWidth - 1 && gameBoard[row][column].substr(gameBoard[row][column].find('g') + 1, gameBoard[row][column].find('c') - (gameBoard[row][column].find('g') + 1)) == gameBoard[row][column + 1].substr(gameBoard[row][column + 1].find('g') + 1, gameBoard[row][column + 1].find('c') - (gameBoard[row][column + 1].find('g') + 1)) && gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1)) != gameBoard[row][column + 1].substr(gameBoard[row][column + 1].find('c') + 1, gameBoard[row][column + 1].length() - (gameBoard[row][column + 1].find('c') + 1)))
    {
        test = 4;
        gameBoard[row][column + 1] = gameBoard[row][column + 1].substr(0, gameBoard[row][column + 1].find('c') + 1) + gameBoard[row][column].substr(gameBoard[row][column].find('c') + 1, gameBoard[row][column].length() - (gameBoard[row][column].find('c') + 1));
        if (!isFalling(row, column + 1))
        {
            fallResult = false;
        }
    }
    return fallResult;
}

void fall()
{
    for (int i = gameHeight - 2; i >= 0; i--)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j] != "0")
            {
                callIndex++;
                gameBoard[i][j] = gameBoard[i][j].substr(0, gameBoard[i][j].find('c') + 1) + to_string(callIndex);
                if (isFalling(i, j))
                {
                    //cout << gameBoard[i][j] << " ";
                    fallingShapeExists = true;
                    gameBoard[i + 1][j] = gameBoard[i][j];
                    gameBoard[i][j] = "0";
                }
            }
        }
    }
}

void showBoard()
{
    system("cls");
    for (int i = 0; i < gameHeight; i++)
    {
        for (int k = 0; k < blockSize; k++)
        {
            for (int j = 0; j < gameWidth; j++)
            {
                color = stoi(gameBoard[i][j].substr(0, gameBoard[i][j].find('g'))) * 16;
                SetConsoleTextAttribute(console, color);
                cout << setfill(' ') << setw(blockSize * gameRatio) << "";
            }
            cout << endl;
        }
    }
    SetConsoleTextAttribute(console, 0);
    cout << setfill('-') << setw(gameWidth * blockSize * gameRatio) << "" << endl;
}

void addBlockToGroup(int color, int row, int column, int size, bool addGroup)
{
    int random = rand() % ((size < 3) ? size : 3) + 1;
    int r = -1, c = -1;
    string blockSelectionText = "0123";
    if (addGroup)
    {
        gameBoard[row][column] = to_string(color) + "g" + to_string(groupIndex) + "c0";
        r = row;
        c = column;
    }
    else
    {
        if (column <= 0 || gameBoard[row][column - 1] != "0")
        {
            blockSelectionText.replace(blockSelectionText.find('0'), 1, "");
        }
        if (row >= gameWidth - 1 || gameBoard[row + 1][column] != "0")
        {
            blockSelectionText.replace(blockSelectionText.find('1'), 1, "");
            
        }
        if (column >= gameHeight - 1 || gameBoard[row][column + 1] != "0")
        {
            blockSelectionText.replace(blockSelectionText.find('2'), 1, "");
        }
        if (row <= 0 || gameBoard[row - 1][column] != "0")
        {
            blockSelectionText.replace(blockSelectionText.find('3'), 1, "");
        }
        for (int i = 0; i < random; i++)
        {
            random = (blockSelectionText.length() != 0) ? rand() % blockSelectionText.length() : -1;
            if (random != -1)
            {
                random = blockSelectionText[random] - '0';
            }
            if (random == 0)
            {
                r = row;
                c = column - 1;
            }
            else if (random == 1)
            {
                r = row + 1;
                c = column;
            }
            else if (random == 2)
            {
                r = row;
                c = column + 1;
            }
            else if (random == 3)
            {
                r = row - 1;
                c = column;
            }
            if (r != -1 && c != -1)
            {
                gameBoard[r][c] = to_string(color) + "g" + to_string(groupIndex) + "c0";
                size--;
            }
        }
    }
    
    if (size > 0 && r != -1 && c != -1)
    {
        addBlockToGroup(color , r, c, size, false);
    }
}

void moveLeft()
{
    int counter = 0;
    string shapeInfo[maxShapeSize];
    for (int i = 0; i < maxShapeSize; i++)
    {
        shapeInfo[i] = "0";
    }
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex))
            {
                if (j == 0 || (gameBoard[i][j - 1] != "0" && gameBoard[i][j - 1].substr(gameBoard[i][j - 1].find('g') + 1, gameBoard[i][j - 1].find('c') - (gameBoard[i][j - 1].find('g') + 1)) != to_string(groupIndex)))
                {
                    return;
                }
            }
        }
    }
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex))
            {
                shapeInfo[counter] = gameBoard[i][j] + "y" + to_string(i) + "x" + to_string(j - 1);
                gameBoard[i][j] = "0";
                counter++;
            }
        }
    }
    //cout << shapeInfo << " ";
    for (int i = 0; i < counter; i++)
    {
        //cout << shapeInfo[i].substr(0, shapeInfo[counter].find('y')) << " ";
        //cout << shapeInfo[i] << " ";
        gameBoard[stoi(shapeInfo[i].substr(shapeInfo[i].find('y') + 1, shapeInfo[i].find('x') - (shapeInfo[i].find('y') + 1)))][stoi(shapeInfo[i].substr(shapeInfo[i].find('x') + 1, shapeInfo[i].length() - (shapeInfo[i].find('x') + 1)))] = shapeInfo[i].substr(0, shapeInfo[i].find('y'));
    }
    showBoard();
}

void moveRight()
{
    int counter = 0;
    string shapeInfo[maxShapeSize];
    for (int i = 0; i < maxShapeSize; i++)
    {
        shapeInfo[i] = "0";
    }
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex))
            {
                if (j == gameWidth - 1 || (gameBoard[i][j + 1] != "0" && gameBoard[i][j + 1].substr(gameBoard[i][j + 1].find('g') + 1, gameBoard[i][j + 1].find('c') - (gameBoard[i][j + 1].find('g') + 1)) != to_string(groupIndex)))
                {
                    return;
                }
            }
        }
    }
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex))
            {
                shapeInfo[counter] = gameBoard[i][j] + "y" + to_string(i) + "x" + to_string(j + 1);
                gameBoard[i][j] = "0";
                counter++;
            }
        }
    }
    //cout << shapeInfo << " ";
    for (int i = 0; i < counter; i++)
    {
        //cout << shapeInfo[i].substr(0, shapeInfo[counter].find('y')) << " ";
        //cout << shapeInfo[i] << " ";
        gameBoard[stoi(shapeInfo[i].substr(shapeInfo[i].find('y') + 1, shapeInfo[i].find('x') - (shapeInfo[i].find('y') + 1)))][stoi(shapeInfo[i].substr(shapeInfo[i].find('x') + 1, shapeInfo[i].length() - (shapeInfo[i].find('x') + 1)))] = shapeInfo[i].substr(0, shapeInfo[i].find('y'));
    }
    showBoard();
}

void rotate()
{
    int counter = 0;
    string shapeInfo[maxShapeSize];
    int center[2];
    int maxX = -1, minX = -1, minY = -1, maxY = -1;
    for (int i = 0; i < maxShapeSize; i++)
    {
        shapeInfo[i] = "0";
    }
    
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex))
            {
                if (minY == -1) minY = i;
                if (maxY == -1) maxY = i;
                if (minX == -1) minX = j;
                if (maxX == -1) maxX = j;
                if (maxY != -1 && i > maxY)  maxY = i;
                if (minX != -1 && j < minX)  minX = j;
                if (maxX != -1 && j > maxX)  maxX = j;
                // minY = i;
                // maxY = i;
                // minX = j;
                // maxX = j;
                cout << "p";
            }
        }
    }
    center[0] = (maxX + minX)/2;
    center[1] = (maxY + minY)/2;
    //SetConsoleTextAttribute(console, 12);
    //cout << "minX: " + to_string(minX) << " maxX: " + to_string(maxX) << " minY: " + to_string(minY) << " maxY: " + to_string(maxY);
    //cout << " " << center[0] << " " << center[1] << endl;
    //system("pause");
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex) && gameBoard[center[0] - (center[0] - j)][center[1] + (center[1] - i)] != "0" && gameBoard[center[0] - (center[0] - j)][center[1] + (center[1] - i)].substr(gameBoard[center[0] - (center[0] - j)][center[1] + (center[1] - i)].find('g') + 1, gameBoard[center[0] - (center[0] - j)][center[1] + (center[1] - i)].find('c') - (gameBoard[center[0] - (center[0] - j)][center[1] + (center[1] - i)].find('g') + 1)) != to_string(groupIndex))
            {
                return;
            }
        }
    }
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j].substr(gameBoard[i][j].find('g') + 1, gameBoard[i][j].find('c') - (gameBoard[i][j].find('g') + 1)) == to_string(groupIndex))
            {
                shapeInfo[counter] = gameBoard[i][j] + "y" + to_string(center[1] - (center[0] - j)) + "x" + to_string(center[0] + (center[1] - i));
                gameBoard[i][j] = "0";
                counter++;
            }
        }
    }
    for (int i = 0; i < counter; i++)
    {
        //cout << shapeInfo[i].substr(0, shapeInfo[counter].find('y')) << " ";
        //cout << shapeInfo[i] << " ";
        gameBoard[stoi(shapeInfo[i].substr(shapeInfo[i].find('y') + 1, shapeInfo[i].find('x') - (shapeInfo[i].find('y') + 1)))][stoi(shapeInfo[i].substr(shapeInfo[i].find('x') + 1, shapeInfo[i].length() - (shapeInfo[i].find('x') + 1)))] = shapeInfo[i].substr(0, shapeInfo[i].find('y'));
    }
    showBoard();
    //system("pause");
}

void checkFullRow()
{
    bool isFullRow = true;
    for (int i = 0; i < gameHeight; i++)
    {
        isFullRow = true;
        for (int j = 0; j < gameWidth; j++)
        {
            if (gameBoard[i][j] == "0")
            {
                isFullRow = false;
            }
        }
        if (isFullRow)
        {
            for (int j = 0; j < gameWidth; j++)
            {
                gameBoard[i][j] = "0";   
            }
        }
    }
}

void isGameOver()
{
    for (int i = 0; i < gameWidth; i++)
    {
        if (gameBoard[loseHeight][i] != "0")
        {
            lose = true;
        }
    }
}