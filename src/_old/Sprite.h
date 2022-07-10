//
// Created by znnxz on 19-Jun-22.
//

#ifndef SDL_APP_SPRITE_H
#define SDL_APP_SPRITE_H

#include "SDL.h"

class Sprite {
public:
    Sprite(int index);
    void Draw(SDL_Renderer* renderer, int x, int y);
private:
    SDL_Texture* texture;
    SDL_Rect source;
    SDL_Rect target;
};


#endif //SDL_APP_SPRITE_H
