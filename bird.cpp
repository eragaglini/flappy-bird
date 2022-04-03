#include "bird.hpp"
#include "load_texture.hpp"
#include <stdexcept>

#include <iostream>

Bird::Bird(SDL_Renderer * renderer) : renderer(renderer), 
        bird1(load_texture(renderer, "bird1.bmp")), 
        bird2(load_texture(renderer, "bird2.bmp"))
        {};

void Bird::draw() {
    SDL_Rect r;
    r.x = x - 64;
    r.y = y - 64;
    r.w = 128;
    r.h = 128; 
    auto res = SDL_RenderCopyEx(renderer, SDL_GetTicks64() % 300 > 150 ? bird1 : bird2, nullptr, &r, v*50, nullptr, SDL_FLIP_NONE);
    if (res != 0) {
        throw std::runtime_error(std::string("SDL_RenderCopy error: ") + SDL_GetError());
    }
}

void Bird::tick(SDL_bool isSpacePressed)
{
  v -= isSpacePressed ? 0.003 : 0;
  v += 0.001;
  y += v;
}

Bird::~Bird() {
  SDL_DestroyTexture(bird1);
  SDL_DestroyTexture(bird2);
}