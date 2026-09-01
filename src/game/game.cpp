#include <iostream>

#include "game/game.hpp"

namespace game
{

Game::Game() = default;

Game::~Game()
{
    if (renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
    }

    if (window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
    }

    SDL_Quit();
}

bool Game::initialize()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDLInit failed: "
                  << SDL_GetError()
                  << '\n';

        return false;
    }

    window_ = SDL_CreateWindow(
        "SDL3 Game",
        1280,
        720,
        0
    );

    if (window_ == nullptr)
    {
        std::cerr << "SDL_CreateWindow faild: "
                  << SDL_GetError()
                  << '\n';

        return false;
    }

    renderer_ = SDL_CreateRenderer(
        window_,
        nullptr
    );

    if (renderer_ == nullptr)
    {
        std::cerr << "SDL_CreateRenderer failed: "
                  << SDL_GetError()
                  << '\n';

        return false;
    }

    running_ = true;

    return true;
}

void Game::run()
{
    while (running_)
    {
        process_events();
        update();
        render();
    }
}

void Game::process_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            running_ = false;
        }
    }
}

void Game::update()
{
    // Game logic
}

void Game::render()
{
    SDL_SetRenderDrawColor(
        renderer_,
        20,
        30,
        40,
        SDL_ALPHA_OPAQUE
    );

    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);
}

} // namespace game