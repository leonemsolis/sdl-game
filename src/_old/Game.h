#ifndef SDL_APP_GAME_H
#define SDL_APP_GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "Scene.h"

class Game {
public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    void Run();
private:
    void Initialize();
    void GameLoop();
    void Destroy();
    bool running;
    Scene* currentScene;

    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif //SDL_APP_GAME_H
