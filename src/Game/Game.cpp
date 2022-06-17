//
// Created by znnxzz on 17-Jun-22.
//

#include "Game.h"
#include <iostream>

void Game::Start() {
    std::cout<<"START"<<std::endl;
}

void Game::Update(float deltaTime) {
    std::cout<<"UPDATE"<<std::endl;
}

void Game::Draw(SDL_Renderer *renderer) {
    std::cout<<"DRAW"<<std::endl;
}

void Game::Quit() {
    std::cout<<"QUIT"<<std::endl;
}
