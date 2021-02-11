#include <iostream>
#include <list>
#include <cmath>
#include <ctime>
#include "block.hpp"

using namespace std;

class Shape
{
    public:
        size_t id;
        size_t groupId;
        size_t blockCount;
        size_t color;
        bool isFalling;
        bool canMoveRight;
        bool canMoveLeft;
        Block blockInstance;
        list<Block> groupBlocks;

        Shape();
        Shape(size_t id, size_t minCount, size_t maxCount, size_t minY, size_t maxY, size_t minX, size_t maxX);
        Shape* moveShapeDown();
        Shape* deleteBlock(int blockId);
        Shape* fixShape(list<Shape>& shapesList);
        Block& findByBID(size_t blockId);
        void debug();
        // Shape* rotateShape();
        bool moveShapeRight();
        bool moveShapeLeft();
};

Shape::Shape()
{

}

Shape::Shape(size_t id, size_t minCount, size_t maxCount, size_t minY, size_t maxY, size_t minX, size_t maxX)
{
    // Setup
    srand(time(0));
    this->id = 1;
    this->groupId = id;
    this->isFalling = true;
    this->canMoveLeft = true;
    this->canMoveRight = true;
    this->color =  ((rand() % 15) + 1) * 16;
    bool repeated, interrupted;
    Position currentBlockPos;

    // Choose a suitable random block count
    minCount  = (((maxX - minX) * (maxY - minY)) < minCount) ? ((maxX - minX) * (maxY - minY)) : minCount;
    while(true)
    {
        this->blockCount = (rand() % (maxCount - minCount)) + minCount;
        if (this->blockCount <= ((maxX - minX) * (maxY - minY))) break;
    }
    // Create a shape
    for (size_t i = 0; i < this->blockCount; i++)
    {
        // Choose a position for a new block without repeat or interruption 
        do {
            repeated = false;
            interrupted = true;
            currentBlockPos.x = (rand() % (maxX - minX)) + minX;
            currentBlockPos.y = (rand() % (maxY - minY)) + minY;
            for (Block block : this->groupBlocks)
            {
                // Check repeat
                if (block.pos.x == currentBlockPos.x && block.pos.y == currentBlockPos.y)
                {
                    repeated = true;
                    break;
                }
                // Check interruption
                if (block.pos.x + 1 == currentBlockPos.x && block.pos.y == currentBlockPos.y)
                {
                    interrupted = false;
                }
                else if (block.pos.x - 1 == currentBlockPos.x && block.pos.y == currentBlockPos.y)
                {
                    interrupted = false;
                }
                else if (block.pos.x == currentBlockPos.x && block.pos.y + 1 == currentBlockPos.y)
                {
                    interrupted = false;
                }
                else if (block.pos.x == currentBlockPos.x && block.pos.y - 1 == currentBlockPos.y)
                {
                    interrupted = false;
                }
            }
        } while((repeated || interrupted) && i != 0);
        // Set block info
        blockInstance.pos.x = currentBlockPos.x;
        blockInstance.pos.y = currentBlockPos.y;
        blockInstance.groupId = this->groupId;
        blockInstance.velocity = 1;
        blockInstance.isFalling = true;
        blockInstance.color = this->color;
        blockInstance.blockId = this->id;
        // Add block to shape
        groupBlocks.push_back(blockInstance);
    }
}

Shape* Shape::moveShapeDown()
{
    for (list<Block>::iterator blockItr = this->groupBlocks.begin(); blockItr != this->groupBlocks.end(); blockItr++)
    {
        if (blockItr->isFalling) blockItr->pos.y -= 1;
    }
    return this;
}

Block& Shape::findByBID(size_t blockId)
{
    for (list<Block>::iterator blockItr = this->groupBlocks.begin(); blockItr != this->groupBlocks.end(); blockItr++)
    {
        if (blockItr->blockId == blockId)
        {
            return *blockItr;
        }
    }
}

void Shape::debug()
{
    for (Block block : this->groupBlocks)
    {
        cout << "X: " << block.pos.x;
        cout << ", Y: " << block.pos.y;
        cout << ", Color: " << block.color;
        cout << ", GID: " << block.groupId;
        cout << ", Speed: " << block.velocity;
        cout << ", Fall: " << block.isFalling << "   " << this->groupBlocks.size() << endl;
    }
}

bool Shape::moveShapeRight()
{
    if (this->canMoveRight)
    {
        for (list<Block>::iterator blockItr = this->groupBlocks.begin(); blockItr != this->groupBlocks.end(); blockItr++)
        {
            if (blockItr->isFalling) blockItr->pos.x += 1;
        }
        return true;
    }
    return false;
}

bool Shape::moveShapeLeft()
{
    if (this->canMoveLeft)
    {
        for (list<Block>::iterator blockItr = this->groupBlocks.begin(); blockItr != this->groupBlocks.end(); blockItr++)
        {
            if (blockItr->isFalling) blockItr->pos.x -= 1;
        }
        return true;
    }
    return false;
}

Shape* Shape::deleteBlock(int blockId)
{
    for (list<Block>::iterator blockItr = this->groupBlocks.begin(); blockItr != this->groupBlocks.end(); blockItr++)
    {
        if (blockItr->blockId == blockId)
        {
            this->groupBlocks.erase(blockItr);
            break;
        }
    }
    return this;
}

Shape* Shape::fixShape(list<Shape>& shapesList)
{
    Shape tempShape;
    list<Block> tempGroup;
    list<Block> groupInstance = this->groupBlocks;
    list<Block>::iterator blockItr;
    list<Block>::iterator tempBlockItr;
    bool connected = false;
    tempGroup.push_back(groupInstance.front());
    groupInstance.erase(groupInstance.begin());
    blockItr = groupInstance.begin();
    this->groupBlocks.clear();
    while(blockItr != groupInstance.end())
    {
        connected = false;
        tempBlockItr = tempGroup.begin();
        while(tempBlockItr != tempGroup.end())
        {
            if ((blockItr->pos.x == tempBlockItr->pos.x && abs((int) (blockItr->pos.y - tempBlockItr->pos.y)) == 1) || (blockItr->pos.y == tempBlockItr->pos.y && abs((int) (blockItr->pos.x - tempBlockItr->pos.x)) == 1))
            {
                tempGroup.push_back(*blockItr);
                groupInstance.erase(blockItr++);
                connected = true;
                break;
            }
            tempBlockItr++;
        }
        if (!connected) blockItr++;
    }
    for (Block tempBlock : tempGroup)
    {
        this->groupBlocks.push_back(tempBlock);
    }
    this->blockCount = this->groupBlocks.size();
    if (groupInstance.size() > 0)
    {
        tempShape.id = groupInstance.size() + 1;
        tempShape.groupId = shapesList.size() + 1;
        tempShape.blockCount = groupInstance.size();
        tempShape.color = this->color;
        tempShape.isFalling = this->isFalling;
        tempShape.canMoveLeft = this->canMoveLeft;
        tempShape.canMoveRight = this->canMoveRight;
        for (Block tempBlock : groupInstance)
        {
            tempShape.groupBlocks.push_back(tempBlock);
        }
        shapesList.push_back(tempShape);
        shapesList.back().fixShape(shapesList);
    }
    return this;
}