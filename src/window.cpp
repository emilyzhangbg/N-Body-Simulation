#include "window.h"
#include <iostream>

Window::Window(const std::string &title, int width, int height)
: title{title}, width{width}, height{height}
{
    if (!init())
    {
        closed = true;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "failed to init window" << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (window == nullptr)
    {
        std::cerr << "failed to create window" << std::endl;
        return false;
    }

    return true;
}

bool Window::isClosed()
{
    return closed;
}

void Window::pollEvents()
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            closed = true;
            break;
        }
    }

}

Window::Handle Window::getHandle() const
{
    return window;
}