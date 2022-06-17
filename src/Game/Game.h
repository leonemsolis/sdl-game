//
// Created by znnxzz on 17-Jun-22.
//

#ifndef SDL_APP_GAME_H
#define SDL_APP_GAME_H

#include <SDL.h>

class Game {
public:
    void Start();
    void Update(float deltaTime);
    void Draw(SDL_Renderer* renderer);
    void Quit();
};


#endif //SDL_APP_GAME_H
