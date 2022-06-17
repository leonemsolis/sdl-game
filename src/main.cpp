#include "Game/Game.h"
#include <SDL.h>
#include <SDL_image.h>

int main( int argc, char* args[] )
{
    IMG_Init(IMG_INIT_PNG);
    Game* game = new Game();
    game->Start();
    game->Update(100);
    game->Draw(NULL);
    game->Quit();
    return 0;
}