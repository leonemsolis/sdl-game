//
// Created by znnxz on 19-Jun-22.
//

#include <SDL.h>
#include <iostream>
#include "GameScene.h"
#include "Input.h"

GameScene::GameScene() {
    testSprite = new Sprite(2);
    x = 10;
    y = 10;
}

void GameScene::Update() {
    float delta = 10;
    if(Input::Instance().GetKey(SDL_SCANCODE_LEFT)) x-=delta;
    if(Input::Instance().GetKey(SDL_SCANCODE_RIGHT)) x+=delta;
    if(Input::Instance().GetKey(SDL_SCANCODE_UP)) y-=delta;
    if(Input::Instance().GetKey(SDL_SCANCODE_DOWN)) y+=delta;
}

void GameScene::Draw(SDL_Renderer *renderer) {
    testSprite->Draw(renderer, (int)x, (int)y);
}

GameScene::~GameScene() {

}