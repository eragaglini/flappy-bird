#include "tube.hpp"
#include <stdexcept>
#include <string>

Tube::Tube(SDL_Renderer *renderer, SDL_Texture *texture, int y, SDL_bool isUp) :
renderer(renderer),texture(texture),y(y),isUp(isUp) {}

void Tube::tick() {
    x -= 0.25f;
}

void Tube::draw()
{
    SDL_Rect r;
    if (!isUp)
    {
        r.x = x - 128;
        r.y = y; 
        r.w = 256;
        r.h = 720;
        SDL_RenderCopyEx(renderer, texture, nullptr, &r, 0, nullptr, SDL_FLIP_NONE);
    }
    else
    {
        SDL_Rect r;
        r.x = x - 128;
        r.y = y - Application::Height;
        r.w = 256;
        r.h = 720;
        SDL_RenderCopyEx(renderer, texture, nullptr, &r, 0, nullptr, SDL_FLIP_VERTICAL);
    }
}