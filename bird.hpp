#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED
#include <SDL2/SDL.h>
#include "application.hpp"


class Bird
{
    private:
        /* data */
        SDL_Texture *bird1;
        SDL_Texture *bird2;
        SDL_Renderer * renderer;
        float v = 0.0f;
    public:
        float y = Application::Height / 2 - 50;
        const float x = Application::Width / 4 - 50;
        void draw();
        void tick(SDL_bool isSpaceDown);
        Bird(SDL_Renderer * renderer);
        ~Bird();
};


#endif // BIRD_H_INCLUDED