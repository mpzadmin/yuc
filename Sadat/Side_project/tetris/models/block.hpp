struct Position
{
    size_t x;
    size_t y;
};

class Block
{
    public:
        size_t blockId;
        size_t groupId;
        Position pos;
        size_t color;
        size_t velocity;
        bool isFalling;
        std::wstring consoleShape = L"  ";
};