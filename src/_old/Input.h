//
// Created by znnxz on 18-Jun-22.
//

#ifndef SDL_APP_INPUT_H
#define SDL_APP_INPUT_H

#include "SDL.h"
#include "glm/vec2.hpp"

enum InputEventTypes {
    QUIT = 0,
    L_UP,
    L_PRESSED,
    L_DOWN,
    L_RELEASED,
    R_UP,
    R_PRESSED,
    R_DOWN,
    R_RELEASED,
    TOTAL_EVENTS_COUNT,
};

class Input {
private:
    Input();
    bool eventFlags[InputEventTypes::TOTAL_EVENTS_COUNT];
    bool previousKeyboardState[SDL_Scancode::SDL_NUM_SCANCODES];
public:
    Input(Input const&) = delete;
    Input &operator=(Input const&) = delete;
    static Input &Instance();

    void Update();

    bool CheckEvent(InputEventTypes type);

    bool GetKeyDown(SDL_Scancode code);
    bool GetKeyUp(SDL_Scancode code);
    bool GetKey(SDL_Scancode code);

    glm::i32vec2 GetMousePosition();
    bool GetMouseButtonUp(int buttonIndex);
    bool GetMouseButtonDown(int buttonIndex);
    bool GetMouseButton(int buttonIndex);
};


#endif //SDL_APP_INPUT_H
