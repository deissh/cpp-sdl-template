#include <iostream>
#include "roguelike.Game/game.h"

int main() {
    GameArgs args;
    args.width = 800;
    args.height = 800;
    args.vsync = true;
    args.fullscreen = true;

    Game game;
    game.init("Game Title", args);

    return 0;
}