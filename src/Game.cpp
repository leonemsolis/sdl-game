#include "Game.h"

#include <iostream>
#include "Input.h"

void Game::Run() {
    this->Initialize();
    this->Update();
    this->Destroy();
}

void Game::Initialize() {
    //Initialization flag
    running = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        running = false;
        return;
    }

    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        running = false;
        return;
    }

    screenSurface = SDL_GetWindowSurface( window );

    imageSurface = SDL_LoadBMP( "../res/x.bmp" );
    if( imageSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "../res/x.bmp", SDL_GetError() );
        running = false;
    }
}

void Game::Update() {
    SDL_Event e;

    while( running )
    {
        Input::Instance().Update();

        if(Input::Instance().CheckEvent(QUIT)) {
            running = false;
        }

        SDL_BlitSurface( imageSurface, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
    }
}

void Game::Destroy() {
    SDL_FreeSurface( imageSurface );
    imageSurface = NULL;

    SDL_DestroyWindow( window );
    window = NULL;

    SDL_Quit();
}