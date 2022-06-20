//
// Created by znnxz on 19-Jun-22.
//

#include "AssetManager.h"
#include <string>
#include <SDL_image.h>

AssetManager* AssetManager::instance = nullptr;

AssetManager::AssetManager() {
    texture = NULL;
    font = NULL;
    initialized = false;
}

AssetManager* AssetManager::Instance() {
    if(!instance) instance = new AssetManager();
    return instance;
}

bool AssetManager::Initialize(SDL_Renderer* renderer) {
    if(initialized) return true;

    std::string path = "../res/atlas.png";
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return false;
    }

    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    if( texture == NULL ) {
        printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        return false;
    }

//    auto width = loadedSurface->w;
//    auto height = loadedSurface->h;
//    printf("Texture width = %d, height = %d\n", width, height);

    SDL_FreeSurface( loadedSurface );

    font = TTF_OpenFont("../res/font.TTF", 28);
    if(font == NULL) {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        return false;
    }

    initialized = true;
    return initialized;
}

void AssetManager::Destroy() {
    if(!initialized) return;
    TTF_CloseFont(font);
    font = NULL;
    SDL_DestroyTexture(texture);
    texture = NULL;
    initialized = false;
}

SDL_Texture *AssetManager::GetTexture() {
    if(!initialized) return NULL;
    return texture;
}

TTF_Font *AssetManager::GetFont() {
    if(!initialized) return NULL;
    return font;
}