#include <iostream>
#include <windows.h>
#include "models\game.hpp"
#include <io.h>
#include <fcntl.h>

using namespace std;

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    GameSetting setting;
    setting.gameHeight = 25;
    setting.gameWidth = 20;
    setting.minY = 20;
    setting.maxY = 24;
    setting.minX = 0;
    setting.maxX = 1;
    setting.minCameraY = 0;
    setting.maxCameraY = 19;
    setting.minCameraX = 0;
    setting.maxCameraX = 4;
    setting.minCount = 2;
    setting.maxCount = 5;
    setting.size = 1;
    setting.FPS = 5;
    setting.keyPressCooldown = 10;
    setting.updateDelay = 10;
    Game game(setting);
    game.start();
}