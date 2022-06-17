#include "Game/Game.h"

int main( int argc, char* args[] )
{
    Game* game = new Game();
    game->Start();
    game->Update(100);
    game->Draw(NULL);
    game->Quit();
    return 0;
}