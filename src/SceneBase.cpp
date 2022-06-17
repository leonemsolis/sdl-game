//
// Created by znnxzz on 17-Jun-22.
//
#include <SDL.h>

class SceneBase {
public:
    virtual void Open() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(SDL_Renderer* renderer) = 0;
    virtual void Close() = 0;
};

class StartScene : SceneBase {
public:
    void Open() override {
    }

    void Update(float deltaTime) override {

    }

    void Draw(SDL_Renderer* renderer) override {

    }

    void Close() override {

    }
};