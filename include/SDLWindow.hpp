#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include "Window.hpp"
#include <SDL3/SDL.h>  
#include <glad/glad.h>

#include <iostream>

class SDLWindow : public Window {
public:
    SDLWindow(){};
    ~SDLWindow() = default;

    bool create(const char* title, int width, int height) override;

    void destroy() override;
    void handleEvents() override;
    void render() override;
    bool isOpen() const override;

private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isOpen;

};

#endif