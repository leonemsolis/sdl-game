//
// Created by znnxzz on 20-Jun-22.
//

#include "Text.h"
#include <SDL_ttf.h>
#include "AssetManager.h"

Text::Text(std::string text, SDL_Color textColor, SDL_Renderer* renderer) {
    textValue = text;
    color = textColor;
    Setup(renderer);
}

void Text::SetText(std::string text, SDL_Renderer* renderer) {
    textValue = text;
    Setup(renderer);
}

void Text::SetColor(SDL_Color textColor, SDL_Renderer* renderer) {
    color = textColor;
    Setup(renderer);
}

void Text::Setup(SDL_Renderer* renderer) {
    Free();
    SDL_Surface* textSurface = TTF_RenderText_Solid(AssetManager::Instance()->GetFont(), textValue.c_str(), color);
    if(textSurface == NULL) {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        return;
    }
    width = textSurface->w;
    height = textSurface->h;

    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if(texture == NULL) {
        printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        return;
    }

    SDL_FreeSurface(textSurface);
}

void Text::Draw(SDL_Renderer *renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = {x, y, width, height};
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx( renderer, texture, clip, &renderQuad, angle, center, flip );
}

void Text::Free() {
    if(texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

Text::~Text() {
    Free();
}