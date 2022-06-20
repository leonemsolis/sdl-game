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
    void Update() override;
    void Draw(SDL_Renderer *renderer) override;
    ~GameScene() override;

private:
    Sprite* testSprite;
    float x;
    float y;
};


#endif //SDL_APP_GAMESCENE_H
