#include "game.h"
#include "iostream"

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, GameArgs args) {
    int initFlags = SDL_INIT_VIDEO
        | SDL_INIT_TIMER
        | SDL_INIT_AUDIO;

    if (SDL_Init(initFlags) != 0) {
        std::cout << "ERR: sdl not initialised!" << std::endl;
        return;
    }

    int flags = SDL_WINDOW_OPENGL;

    if (args.fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(
        title,
        args.xpos,
        args.ypos,
        args.width,
        args.height,
        flags
    );
    if (!window) {
        std::cout << "ERR: window not initialised!" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cout << "ERR: window not initialised!" << std::endl;
        return;
    }

    while(true) {

    }
}