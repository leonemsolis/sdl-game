#include "Game.h"

#include <iostream>
#include "Input.h"
#include "GameScene.h"
#include "AssetManager.h"
#include "Constants.h"
#include <SDL_ttf.h>

void Game::Run() {
    this->Initialize();
    this->GameLoop();
    this->Destroy();
}

void Game::Initialize() {
    running = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        running = false;
        return;
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    {
        printf( "Warning: Linear texture filtering not enabled!" );
    }

    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        running = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        running = false;
        return;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not be initialized! SDL_image Error: %s\n", SDL_GetError());
        running = false;
        return;
    }

    if(TTF_Init() == -1) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        running = false;
        return;
    }

    if(!AssetManager::Instance()->Initialize(renderer)) {
        printf("AssetManager failed to load\n");
        running = false;
        return;
    }

    currentScene = new GameScene(renderer);
}

void Game::GameLoop() {
    Uint64 previous = SDL_GetTicks64();
    Uint64 lag = 0;
    while( running )
    {
        Uint64 current = SDL_GetTicks64();
        Uint64 elapsed = current - previous;
        previous = current;
        lag += elapsed;

        while(lag >= FRAME_TARGET_TIME) {
            Input::Instance().Update();
            if(Input::Instance().CheckEvent(QUIT)) {
                running = false;
            }
            currentScene->Update();
            lag -= FRAME_TARGET_TIME;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
        currentScene->Draw(renderer);
        SDL_RenderPresent(renderer);
    }
}

void Game::Destroy() {
    delete currentScene;

    AssetManager::Instance()->Destroy();

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow( window );
    window = NULL;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}