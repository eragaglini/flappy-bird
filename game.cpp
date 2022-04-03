#include "game.hpp"

int Game::exec()
{
    SDL_bool loopShouldStop = SDL_FALSE;
    auto oldTick = SDL_GetTicks64();
    SDL_bool isMouseDown = SDL_FALSE;
    while (!loopShouldStop)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                isMouseDown = SDL_TRUE;
                break;
            case SDL_MOUSEBUTTONUP:
                isMouseDown = SDL_FALSE;
                break;
            case SDL_QUIT:
                loopShouldStop = SDL_TRUE;
                break;
            }
        }

        auto currentTick = SDL_GetTicks64();
        for (auto i = oldTick; i < currentTick; i++)
        {
            /* code */
            if (!tick(isMouseDown)){
                SDL_Delay(4000);
                return 1;
            }
        }
        oldTick = currentTick;

        // frame logic here
        SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
        SDL_RenderClear(renderer);
        bird.draw();
        for (auto &tube : tubeList)
        {
            /* code */
            tube.draw();
        }
        SDL_RenderPresent(renderer);
    }
    return 0;
}

SDL_bool Game::tick(SDL_bool isMouseDown)
{
    // std::vector::emplace_back
    // Inserts a new element at the end of the vector, right after its current last element.
    // This new element is constructed in place using args as the arguments for its constructor.
    if (counter++ % 2000 == 0){
        auto y = rand() % (Application::Height - 200 - 250 - 100) + 100;
        tubeList.emplace_back(renderer, tubeTexture, y + 250, SDL_FALSE);
        tubeList.emplace_back(renderer, tubeTexture, y, SDL_TRUE);
    }
    bird.tick(isMouseDown);
    SDL_Rect birdRect;
    birdRect.x = bird.x - 114 / 2;
    birdRect.y = bird.y - 94 / 2;
    birdRect.w = 114;
    birdRect.h = 94;

    if (bird.y < Application::Height)
        isMouseDown = SDL_TRUE;
    else
        isMouseDown = SDL_FALSE;

    SDL_Rect res;
    for (auto &tube : tubeList)
    {
        /* code */
        tube.tick();
        SDL_Rect tubeRect;
        tubeRect.x = tube.x - 128 + 20;
        tubeRect.w = 256 - 40;
        tubeRect.h = 10000;
        if (tube.isUp)
        {
            tubeRect.y = tube.y - 10000;
            if (SDL_IntersectRect(&birdRect, &tubeRect, &res))
            {
                return SDL_FALSE;
            }
        }
        else
        {
            tubeRect.y = tube.y;
            if (SDL_IntersectRect(&birdRect, &tubeRect, &res))
            {
                return SDL_FALSE;
            }
        }
    }
    for (auto iter = std::begin(tubeList); iter != std::end(tubeList); )
    {
        if (iter->x < -128)
            iter = tubeList.erase(iter);
        else
        ++iter;
    }
    return isMouseDown;
}

Game::~Game()
{
    SDL_DestroyTexture(tubeTexture);
}