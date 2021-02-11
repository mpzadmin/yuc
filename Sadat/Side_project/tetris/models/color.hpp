#include <windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(size_t color)
{
    SetConsoleTextAttribute(console, color);
}