//
// Created by znnxz on 19-Jun-22.
//

#include "Sprite.h"
#include "AssetManager.h"

Sprite::Sprite(int index) {
    texture = AssetManager::Instance()->GetTexture();
    switch (index) {
        case 0:
            source = SDL_Rect{0, 0, 16, 16};
            break;
        case 1:
            source = SDL_Rect{16, 0, 16, 16};
            break;
        case 2:
            source = SDL_Rect{0, 16, 16, 16};
            break;
        default:
            source = SDL_Rect{16, 16, 16, 16};
            break;
    }
    target = SDL_Rect{0, 0, 16, 16};
}

void Sprite::Draw(SDL_Renderer* renderer, int x, int y) {
    target.x = x;
    target.y = y;
    SDL_RenderCopy(renderer, texture, &source, &target);
}