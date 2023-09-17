#include "renderer.h"
#include <iostream>

Renderer::Renderer(const Window& window)
: window{window}
{
    init();
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
}

bool Renderer::init()
{
    renderer = SDL_CreateRenderer(window.getHandle(), -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        std::cerr << "failed to create renderer" << std::endl;
        return false;
    }

    return true;
}

void Renderer::clearWindow()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}

Renderer::Handle Renderer::getHandle() const
{
    return renderer;
}