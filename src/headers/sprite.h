//
// Created by znnxz on 10-Jul-22.
//

#ifndef SDL_APP_SPRITE_H
#define SDL_APP_SPRITE_H

#include <SDL.h>
#include <string>

class Graphics;

class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
private:
    float _x, _y;
};

#endif //SDL_APP_SPRITE_H
