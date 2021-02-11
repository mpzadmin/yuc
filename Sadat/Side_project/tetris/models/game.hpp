#include <iostream>
#include <list>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "shape.hpp"
#include "color.hpp"
#include <io.h>
#include <fcntl.h>

using namespace std;

struct GameSetting
{
    int gameHeight;
    int gameWidth;
    int minCameraX;
    int maxCameraX;
    int minCameraY;
    int maxCameraY;
    int minY;
    int maxY;
    int minX;
    int maxX;
    int minCount;
    int maxCount;
    int size;
    int FPS;
    int updateDelay;
    int keyPressCooldown;
};
struct GameBoardInfo
{
    int color;
    int groupId;
    int blockId;
    wstring consoleShape;
};

class Game
{
    private:
        int id;
        int minY;
        int maxY;
        int minX;
        int maxX;
        int minCameraX;
        int maxCameraX;
        int minCameraY;
        int maxCameraY;
        int minCount;
        int maxCount;
        int gameHeight;
        int gameWidth;
        int cameraHeight;
        int cameraWidth;
        int size;
        int FPS;
        int updateDelay;
        int keyPressCooldown;
        list<Shape> shapes;
        vector<vector<GameBoardInfo>> board;

    public:
        Game(GameSetting gameSetting);
        Game* addShape();
        bool isFalling();
        Game* adjustRightMovement();
        Game* adjustLeftMovement();
        Game* fillBoard();
        Game* resetBoard();
        Game* updateBoard();
        Game* showBoard();
        Shape& findByGID(int groupId);
        Game* deleteShape(int groupId);
        Game* start();
        Game* moveShapesDown();
        Game* debug();
        Game* deleteFullRow();
        bool isFailed();
};

Game::Game(GameSetting gameSetting)
{
    this->gameHeight = gameSetting.gameHeight;
    this->gameWidth = gameSetting.gameWidth;
    this->id = 1;
    this->minY = gameSetting.minY;
    this->maxY = gameSetting.maxY;
    this->minX = gameSetting.minX;
    this->maxX = gameSetting.maxX;
    this->minCameraY = gameSetting.minCameraY;
    this->maxCameraY = gameSetting.maxCameraY;
    this->minCameraX = gameSetting.minCameraX;
    this->maxCameraX = gameSetting.maxCameraX;
    this->cameraHeight = this->maxCameraY - this->minCameraY + 1;
    this->cameraWidth = this->maxCameraX - this->minCameraX + 1;
    this->minCount = gameSetting.minCount;
    this->maxCount = gameSetting.maxCount;
    this->size = gameSetting.size;
    this->FPS = gameSetting.FPS;
    this->updateDelay = gameSetting.updateDelay;
    this->keyPressCooldown = gameSetting.keyPressCooldown;
    this->fillBoard();
}

Game* Game::fillBoard()
{
    GameBoardInfo info = {0, 0, 0, L"  "};
    vector<GameBoardInfo> infoList;
    for (size_t i = 0; i < this->gameHeight; i++)
    {
        infoList.clear();
        for (size_t j = 0; j < this->gameWidth; j++)
        {
            infoList.push_back(info);
        }
        this->board.push_back(infoList);
    }
    return this;
}

Game* Game::resetBoard()
{
    GameBoardInfo info = {0, 0, 0, L"  "};
    for (size_t i = 0; i < this->gameHeight; i++)
    {
        for (size_t j = 0; j < this->gameWidth; j++)
        {
            this->board[i][j] = info;
        }
    }
    return this;
}

Game* Game::updateBoard()
{
    for (Shape shape : this->shapes)
    {
        for (Block block : shape.groupBlocks)
        {
            if (block.pos.y < this->gameHeight && block.pos.x < this->gameWidth)
            {
                this->board[block.pos.y][block.pos.x].color = block.color;
                this->board[block.pos.y][block.pos.x].consoleShape = block.consoleShape;
                this->board[block.pos.y][block.pos.x].groupId = block.groupId;
                this->board[block.pos.y][block.pos.x].blockId = block.blockId;
            }
        }
    }
    return this;
}

Game* Game::addShape()
{
    Shape ShapeInstance(this->id, this->minCount, this->maxCount, this->minY, this->maxY, this->minX, this->maxX);
    this->shapes.push_back(ShapeInstance);
    this->id++;
    return this;
}

Game* Game::showBoard()
{
    for (int i = this->maxCameraY; i >= minCameraY; i--)
    {
        for (size_t index = 0; index < this->size; index++)
        {
            for (size_t j = minCameraX; j <= this->maxCameraX; j++)
            {
                setColor(this->board[i][j].color);
                for (size_t k = 0; k < this->size; k++)
                {
                    wcout << this->board[i][j].consoleShape;
                }
            }
            wcout << endl;
        }
    }
    setColor(16);
    for (size_t i = 0; i < this->size; i++)
    {
        wcout << setfill(L'X') << setw(this->cameraWidth * 2 * this->size) << L"" << endl;
    }
    setColor(7);
    return this;
}

Shape& Game::findByGID(int groupId)
{
    for (list<Shape>::iterator shapeItr = this->shapes.begin(); shapeItr != this->shapes.end(); shapeItr++)
    {
        if (shapeItr->groupId == groupId)
        {
            return *shapeItr;
        }
    }
}

Game* Game::debug()
{
    for (Shape shape : this->shapes)
    {
        shape.debug();
        cout << endl;
    }
    return this;
}

bool Game::isFalling()
{
    for (list<Shape>::iterator shapeItr = this->shapes.begin(); shapeItr != this->shapes.end(); shapeItr++)
    {
        shapeItr->isFalling = true;
    }
    for (size_t i = 0; i < this->gameHeight; i++)
    {
        for (size_t j = 0; j < this->gameWidth; j++)
        {
            if (this->board[i][j].groupId != 0 && (i == 0 || (this->board[i - 1][j].groupId != 0 && this->board[i - 1][j].groupId != this->board[i][j].groupId && !this->findByGID(this->board[i - 1][j].groupId).isFalling)))
            {
                (this->findByGID(this->board[i][j].groupId)).isFalling = false;
            }
        }
    }
    for (Shape shape : this->shapes)
    {
        if (shape.isFalling) return true;
    }
    return false;
}

Game* Game::start()
{
    int updateCounter = 0;
    int cooldown = 0;
    bool fastForward = false;
    this->addShape();
    while(true)
    {
        if (updateCounter >= ((1000 / this->updateDelay) / this->FPS))
        {
            system("cls");
            this->resetBoard()->updateBoard()->showBoard();
            if (!this->isFalling())
            {
                fastForward = false;
                this->addShape();
            }
            this->deleteFullRow()->resetBoard()->updateBoard()->adjustRightMovement()->adjustLeftMovement()->moveShapesDown();
            updateCounter = 0;
        }
        if ((GetKeyState(VK_LEFT) & 0xf000) && cooldown <= 0)
        {
            if (this->findByGID(this->shapes.back().groupId).moveShapeLeft())
            {
                system("cls");
                this->resetBoard()->updateBoard()->showBoard()->adjustLeftMovement()->adjustRightMovement();
                cooldown = this->keyPressCooldown;
            }
        }
        else if ((GetKeyState(VK_RIGHT) & 0xf000) && cooldown <= 0)
        {
            if (this->findByGID(this->shapes.back().groupId).moveShapeRight())
            {
                system("cls");
                this->resetBoard()->updateBoard()->showBoard()->adjustLeftMovement()->adjustRightMovement();
                cooldown = this->keyPressCooldown;
            }
        }
        if ((GetKeyState(VK_DOWN) & 0xf000) && !fastForward)
        {
            fastForward = true;
        }
        if (cooldown > 0) cooldown -= (fastForward) ? 2 : 1;
        updateCounter += (fastForward) ? 2 : 1;
        if (this->isFailed()) break;
        Sleep(this->updateDelay);
    }
    return this;
}

bool Game::isFailed()
{
    for (size_t i = this->minCameraX; i <= this->maxCameraX; i++)
    {
        if (this->board[maxCameraY][i].groupId != 0 && !this->findByGID(this->board[maxCameraY][i].groupId).isFalling) return true;
    }
    return false;
}

Game* Game::moveShapesDown()
{
    for (list<Shape>::iterator shapeItr = this->shapes.begin(); shapeItr != this->shapes.end(); shapeItr++)
    {
        if (shapeItr->isFalling) shapeItr->moveShapeDown();
    }
    return this;
}

Game* Game::adjustLeftMovement()
{
    for (list<Shape>::iterator shapeItr = this->shapes.begin(); shapeItr != this->shapes.end(); shapeItr++)
    {
        shapeItr->canMoveLeft = true;
    }
    for (size_t i = 0; i < this->gameHeight; i++)
    {
        for (size_t j = this->minCameraX; j <= this->maxCameraX; j++)
        {
            if (this->board[i][j].groupId != 0 && (j == this->minCameraX || (this->board[i][j - 1].groupId != 0 && this->board[i][j - 1].groupId != this->board[i][j].groupId)))
            {
                (this->findByGID(this->board[i][j].groupId)).canMoveLeft = false;
            }
        }
    }
    return this;
}

Game* Game::adjustRightMovement()
{
    for (list<Shape>::iterator shapeItr = this->shapes.begin(); shapeItr != this->shapes.end(); shapeItr++)
    {
        shapeItr->canMoveRight = true;
    }
    for (size_t i = this->minCameraY; i <= this->maxCameraY; i++)
    {
        for (size_t j = this->minCameraX; j <= this->maxCameraX; j++)
        {
            if (this->board[i][j].groupId != 0 && (j == this->maxCameraX || (this->board[i][j + 1].groupId != 0 && this->board[i][j + 1].groupId != this->board[i][j].groupId)))
            {
                (this->findByGID(this->board[i][j].groupId)).canMoveRight = false;
            }
        }
    }
    return this;
}

Game* Game::deleteFullRow()
{
    bool fullRow;
    for (size_t i = this->minCameraY; i <= this->maxCameraY; i++)
    {
        fullRow = true;
        for (size_t j = this->minCameraX; j <= this->maxCameraX; j++)
        {
            if (this->board[i][j].groupId == 0 || this->findByGID(this->board[i][j].groupId).isFalling)
            {
                fullRow = false;
            }
        }
        if (fullRow)
        {
            for (size_t j = this->minCameraX; j <= this->maxCameraX; j++)
            {
                this->findByGID(this->board[i][j].groupId).deleteBlock(this->board[i][j].blockId);
                if (this->findByGID(this->board[i][j].groupId).groupBlocks.size() > 0)
                {
                    this->findByGID(this->board[i][j].groupId).fixShape(this->shapes);
                }
                else
                {
                    this->deleteShape(this->board[i][j].groupId);
                }
                
            }
        }
    }
    return this;
}

Game* Game::deleteShape(int groupId)
{
    for (list<Shape>::iterator shapeItr = this->shapes.begin(); shapeItr != this->shapes.end(); shapeItr++)
    {
        if (shapeItr->groupId == groupId)
        {
            this->shapes.erase(shapeItr);
            break;
        }
    }
    return this;
}