//
// Created by znnxz on 19-Jun-22.
//

#ifndef SDL_APP_GAMESCENE_H
#define SDL_APP_GAMESCENE_H
#include "Scene.h"
#include "Sprite.h"

class GameScene: public Scene {
public:
    GameScene();
    void Update(SDL_Renderer *renderer);
    ~GameScene();

private:
    Sprite* testSprite;
    int x;
    int y;
};


#endif //SDL_APP_GAMESCENE_H
