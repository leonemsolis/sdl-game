//
// Created by znnxz on 19-Jun-22.
//

#ifndef SDL_APP_SCENE_H
#define SDL_APP_SCENE_H
class Scene {
public:
    virtual void Update() = 0;
    virtual void Draw(SDL_Renderer* renderer) = 0;
    virtual ~Scene()= default;;
};


#endif //SDL_APP_SCENE_H
