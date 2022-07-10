//
// Created by znnxz on 19-Jun-22.
//

#include "SDL.h"
#include <iostream>
#include "GameScene.h"
#include "Input.h"

GameScene::GameScene() {
    testSprite = new Sprite(2);
    x = 10;
    y = 10;
}

void GameScene::Update(SDL_Renderer *renderer) {
    if(Input::Instance().GetKey(SDL_SCANCODE_LEFT)) x--;
    if(Input::Instance().GetKey(SDL_SCANCODE_RIGHT)) x++;
    if(Input::Instance().GetKey(SDL_SCANCODE_UP)) y--;
    if(Input::Instance().GetKey(SDL_SCANCODE_DOWN)) y++;
    testSprite->Draw(renderer, x, y);
}

GameScene::~GameScene() {

}