#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <SDL2/SDL.h>

class Application
{
private:
    /* data */
    SDL_Window * window;
    SDL_Renderer * renderer;
public:
    static const auto Width = 1280;
    static const auto Height = 720;
    Application(/* args */);
    ~Application();
    int exec();
};


#endif // APPLICATION_H_INCLUDED