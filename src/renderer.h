#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "window.h"


class Renderer {
public:
    using Handle = SDL_Renderer*;
    Renderer(const Window &window);
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;

    void clearWindow();
    void present();
    
    Handle getHandle() const;
    

private:
    bool init();
    const Window& window;
    Handle renderer = nullptr;
};