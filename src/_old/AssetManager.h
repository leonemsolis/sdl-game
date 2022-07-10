//
// Created by znnxz on 19-Jun-22.
//

#ifndef SDL_APP_ASSETMANAGER_H
#define SDL_APP_ASSETMANAGER_H

#include "SDL.h"

class AssetManager {
private:
    AssetManager();
    static AssetManager* instance;
    SDL_Texture* texture;
    bool initialized;
public:
    // Prevent copying
    AssetManager(AssetManager &other) = delete;
    // Prevent assignment
    void operator=(const AssetManager &) = delete;
    static AssetManager *Instance();
    bool Initialize(SDL_Renderer* renderer);
    void Destroy();
    SDL_Texture* GetTexture();
};


#endif //SDL_APP_ASSETMANAGER_H
