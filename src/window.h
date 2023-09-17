#pragma once

#include <string>
#include <SDL2/SDL.h>

class Window {
public:
    using Handle = SDL_Window*;
    Window(const std::string &title, int width, int height);
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    void pollEvents();
    bool isClosed();
    Handle getHandle() const;

private:
    std::string title;
    int width  = 800;
    int height = 600;
    bool closed = false;

    bool init();

    Handle window = nullptr;
};