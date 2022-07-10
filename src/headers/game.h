//
// Created by znnxz on 10-Jul-22.
//

#ifndef SDL_APP_GAME_H
#define SDL_APP_GAME_H

#include "sprite.h"

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite _player;
};

#endif //SDL_APP_GAME_H
