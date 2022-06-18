#ifndef SDL_APP_GAME_H
#define SDL_APP_GAME_H

#include "SDL.h"

class Game {
public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    void Run();
private:
    void Initialize();
    void Update();
    void Destroy();
    SDL_Surface* screenSurface;
    SDL_Surface* imageSurface;
    SDL_Window* window;
    bool running;
};


#endif //SDL_APP_GAME_H
