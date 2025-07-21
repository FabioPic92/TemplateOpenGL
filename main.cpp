#include <SDL3/SDL.h>

// #define STB_IMAGE_IMPLEMENTATION

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h> 

#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <stb_image.h>

#include "Application.hpp"
#include "SDLWindow.hpp"

#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    Application app;

    app.init();

    auto glWin1 = std::make_unique<SDLWindow>();
    if (!glWin1->create("SDL-OpenGL Window 1", 1024, 768)) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    app.addWindow(std::move(glWin1));

    app.run();

    return 0;
}