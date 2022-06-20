//
// Created by znnxzz on 20-Jun-22.
//

#ifndef SDL_APP_TEXT_H
#define SDL_APP_TEXT_H

#include <SDL.h>
#include <string>

class Text {
public:
    Text(std::string text, SDL_Color textColor, SDL_Renderer* renderer);
    void SetText(std::string text, SDL_Renderer* renderer);
    void SetColor(SDL_Color textColor, SDL_Renderer* renderer);
    void Draw(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    ~Text();
private:
    int width;
    int height;
    SDL_Texture* texture;
    void Free();
    void Setup(SDL_Renderer* renderer);
    std::string textValue;
    SDL_Color color;
};


#endif //SDL_APP_TEXT_H
