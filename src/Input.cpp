#include "Input.h"
#include <SDL.h>
#include <iostream>

Input::Input() {

}

Input& Input::Instance() {
    static Input input;
    return input;
}

void Input::Update() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    for(int i = 0; i < SDL_Scancode::SDL_NUM_SCANCODES; i++) {
        previousKeyboardState[i] = currentKeyStates[i];
    }

    eventFlags[L_PRESSED] = false;
    eventFlags[L_RELEASED] = false;
    eventFlags[R_PRESSED] = false;
    eventFlags[R_RELEASED] = false;

    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        switch (e.type) {
            case SDL_QUIT:
                eventFlags[QUIT] = true;
                break;
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEBUTTONDOWN:
                if(e.button.button == SDL_BUTTON_LEFT) {
                    eventFlags[L_UP] = e.button.state == SDL_RELEASED;
                    eventFlags[L_DOWN] = e.button.state == SDL_PRESSED;
                    eventFlags[L_PRESSED] = e.button.type == SDL_MOUSEBUTTONDOWN;
                    eventFlags[L_RELEASED] = e.button.type == SDL_MOUSEBUTTONUP;
                }
                if(e.button.button == SDL_BUTTON_RIGHT) {
                    eventFlags[R_UP] = e.button.state == SDL_RELEASED;
                    eventFlags[R_DOWN] = e.button.state == SDL_PRESSED;
                    eventFlags[R_PRESSED] = e.button.type == SDL_MOUSEBUTTONDOWN;
                    eventFlags[R_RELEASED] = e.button.type == SDL_MOUSEBUTTONUP;
                }
                break;
        }
    }
}

bool Input::CheckEvent(InputEventTypes type) {
    return eventFlags[type];
}

bool Input::GetKey(SDL_Scancode code) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    return currentKeyStates[code];
}

bool Input::GetKeyUp(SDL_Scancode code) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    return previousKeyboardState[code] && !currentKeyStates[code];
}

bool Input::GetKeyDown(SDL_Scancode code) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    return !previousKeyboardState[code] && currentKeyStates[code];
}

glm::i32vec2 Input::GetMousePosition() {
    glm::i32vec2 position = glm::i32vec2();
    SDL_GetMouseState(&position.x, &position.y);
    return position;
}

bool Input::GetMouseButton(int buttonIndex) {
    if(buttonIndex == 0) {
        return eventFlags[L_DOWN];
    } else {
        return eventFlags[R_DOWN];
    }
}

bool Input::GetMouseButtonDown(int buttonIndex) {
    if(buttonIndex == 0) {
        return eventFlags[L_PRESSED];
    } else {
        return eventFlags[R_PRESSED];
    }
}

bool Input::GetMouseButtonUp(int buttonIndex) {
    if(buttonIndex == 0) {
        return eventFlags[L_RELEASED];
    } else {
        return eventFlags[R_RELEASED];
    }
}