//
// Created by znnxz on 10-Jul-22.
//

#include <SDL.h>

#include "graphics.h"

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
}

