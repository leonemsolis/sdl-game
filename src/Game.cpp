#include "Game.h"

#include <iostream>
#include "Input.h"
#include "GameScene.h"
#include "AssetManager.h"

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

    if(!AssetManager::Instance()->Initialize(renderer)) {
        printf("AssetManager failed to load\n");
        running = false;
        return;
    }

    currentScene = new GameScene();
}

void Game::GameLoop() {
    while( running )
    {
        Input::Instance().Update();

        if(Input::Instance().CheckEvent(QUIT)) {
            running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        currentScene->Update(renderer);

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

    IMG_Quit();
    SDL_Quit();
}