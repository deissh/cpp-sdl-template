#ifndef ROGUELIKE_GAME_H
#define ROGUELIKE_GAME_H

#include <SDL2/SDL.h>

struct GameArgs
{
    int xpos, ypos;
    int width, height;
    bool fullscreen, vsync;
};


class Game {
private:
    bool isRunning();

    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Game();
    ~Game();

    void init(const char* title, GameArgs args);

    // void update();
    // void render();
    // void clean();

    // void handleEvents();
};


#endif //ROGUELIKE_GAME_H
