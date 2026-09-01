#pragma once

#include <SDL3/SDL.h>

namespace game
{

class Game
{
public:
    Game();
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    bool initialize();
    void run();

private:
    void process_events();
    void update();
    void render();

    SDL_Window *window_{nullptr};
    SDL_Renderer *renderer_{nullptr};

    bool running_{false};
};

} // namespace game