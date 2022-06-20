//
// Created by znnxz on 19-Jun-22.
//

#ifndef SDL_APP_ASSETMANAGER_H
#define SDL_APP_ASSETMANAGER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class AssetManager {
private:
    AssetManager();
    static AssetManager* instance;
    bool initialized;

    SDL_Texture* texture;
    TTF_Font* font;
public:
    // Prevent copying
    AssetManager(AssetManager &other) = delete;
    // Prevent assignment
    void operator=(const AssetManager &) = delete;
    static AssetManager *Instance();
    bool Initialize(SDL_Renderer* renderer);
    void Destroy();
    SDL_Texture* GetTexture();
    TTF_Font* GetFont();
};


#endif //SDL_APP_ASSETMANAGER_H
