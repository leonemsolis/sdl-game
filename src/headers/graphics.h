//
// Created by znnxz on 10-Jul-22.
//

#ifndef SDL_APP_GRAPHICS_H
#define SDL_APP_GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif //SDL_APP_GRAPHICS_H
