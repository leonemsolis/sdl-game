//
// Created by znnxz on 10-Jul-22.
//

#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics() {
    IMG_Init(IMG_INIT_PNG);
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyRenderer(this->_renderer);
    this->_renderer = NULL;
    SDL_DestroyWindow(this->_window);
    this->_window = NULL;
    IMG_Quit();
}

SDL_Surface *Graphics::loadImage(const std::string &filePath) {
    if(this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer *Graphics::getRenderer() const {
    return this->_renderer;
}