#include <iostream>

#include "game/game.hpp"

int main()
{
    game::Game game;

    if (!game.initialize())
    {
        std::cerr << "Game initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    game.run();

    return 0;
}