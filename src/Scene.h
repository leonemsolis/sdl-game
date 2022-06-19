//
// Created by znnxz on 19-Jun-22.
//

#ifndef SDL_APP_SCENE_H
#define SDL_APP_SCENE_H
class Scene {
public:
    virtual void Update(SDL_Renderer* renderer) = 0;
    virtual ~Scene(){};
};


#endif //SDL_APP_SCENE_H
