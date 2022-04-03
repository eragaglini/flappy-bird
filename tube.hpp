#ifndef TUBE_H_INCLUDED
#define TUBE_H_INCLUDED
#include "application.hpp"

class Tube
{
  // i don't need destructor because tube doesn't own the texture
  public:
    Tube(SDL_Renderer *renderer, SDL_Texture *texture, int y, SDL_bool isUp);
    void tick();
    void draw();
  private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
  public:
    float x = Application::Width + 128;
    float y;
    SDL_bool isUp;
};



#endif // TUBE_H_INCLUDED