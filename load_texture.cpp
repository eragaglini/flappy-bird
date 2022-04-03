#include "load_texture.hpp"
#include <stdexcept>
// https://stackoverflow.com/questions/21007329/what-is-an-sdl-renderer/21007477#21007477
/*
As mentioned in the last lesson, textures are the GPU rendering equivalent of surfaces. 
Hence, textures are almost always created from surfaces, using the function SDL_CreateTextureFromSurface(). 
This function more or less does what you'd expect—the parameters are the rendering context and a surface 
to create the texture from. As with other creation functions, it will return NULL on failure.
*/
SDL_Texture * load_texture(SDL_Renderer * renderer, const char * fileName) {
    auto surface = SDL_LoadBMP(fileName);
    if(!surface) {
        throw std::runtime_error(std::string("IMG_Load: %s\n", SDL_GetError()));
    }
    auto res = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return res;
}