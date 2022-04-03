#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <vector>
#include "bird.hpp"
#include "tube.hpp"
#include "load_texture.hpp"

class Game
{
private:
    /* data */
    SDL_Renderer * renderer;
    SDL_Texture * tubeTexture;
    Bird bird;
    std::vector<Tube> tubeList;
    int counter = 0;
public:
    Game(SDL_Renderer * renderer) : renderer(renderer), 
    tubeTexture(load_texture(renderer, "tube.bmp")),
    bird(renderer) {}
    int exec();
    ~Game();
    SDL_bool tick(SDL_bool isMouseDown);
};



#endif // GAME_H_INCLUDED