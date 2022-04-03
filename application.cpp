#include "application.hpp"
#include "game.hpp"
#include <stdexcept>
#include <string>


Application::Application(/* args */)
{
    // attempt to initialize graphics system
    auto res = SDL_Init(SDL_INIT_EVERYTHING);
    if (res != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    printf("initialization successful!\n");

    // se va tutto bene ritorna 0, altrimenti torna 1
    //if (SDL_CreateWindowAndRenderer(Width, Height, SDL_WINDOW_BORDERLESS, &window, &renderer)) {
    if (SDL_CreateWindowAndRenderer(Width, Height, 0, &window, &renderer)) {
        printf("Couldn't create window and renderer: %s\n", SDL_GetError());
    }
    else
    {
        printf("window and renderer initialized!\n");
    }
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetWindowPosition(window, 65, 126);
}


Application::~Application()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


int Application::exec()
{
    for (;;)
    {
        /* code */
        Game g(renderer);
        if (g.exec() == 0) {
            break;
        }
    }
    return 0;
}