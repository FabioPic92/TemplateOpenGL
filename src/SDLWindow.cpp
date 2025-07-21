#include "SDLWindow.hpp"
#include <SDL3/SDL.h>

#include <glad/glad.h> 
#include <iostream>

bool SDLWindow::create(const char* title, int width, int height) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create a window
    m_window = SDL_CreateWindow(
        "SDL3 OpenGL Test",
        800,
        600,
        SDL_WINDOW_OPENGL
    );

    if (m_window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    m_glContext = SDL_GL_CreateContext(m_window);
    if (m_glContext == NULL) {
        fprintf(stderr, "OpenGL context could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 1;
    }

    // Make the context current
    if (SDL_GL_MakeCurrent(m_window, m_glContext) < 0) {
        fprintf(stderr, "Failed to make OpenGL context current! SDL_Error: %s\n", SDL_GetError());
        SDL_GL_DestroyContext(m_glContext);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 1;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        SDL_GL_DestroyContext(m_glContext);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 1;
    }
    m_isOpen = true;
    printf("GLAD inizializzato con successo.\n");
    return true;
}

void SDLWindow::destroy() {
    // if (m_glContext) {
    //     SDL_GL_DestroyContext(m_glContext);
    //     m_glContext = nullptr;
    // }
    // if (m_window) {
    //     SDL_DestroyWindow(m_window);
    //     m_window = nullptr;
    // }
    // m_isOpen = false;
    // std::cout << "SDL_OpenGL Window destroyed." << std::endl;
}

void SDLWindow::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EVENT_QUIT) { 
            m_isOpen = false;
        } else if (e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && e.window.windowID == SDL_GetWindowID(m_window)) {
            m_isOpen = false;
        } else if (e.type == SDL_EVENT_WINDOW_RESIZED && e.window.windowID == SDL_GetWindowID(m_window)) {
            int w, h;
            SDL_GetWindowSize(m_window, &w, &h);
            glViewport(0, 0, w, h);
            std::cout << "Window resized to " << w << "x" << h << std::endl;
        }
    }
}

void SDLWindow::render() {
    if (!m_isOpen) return;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Esempio: disegna un triangolo semplice (richiede setup di shader/VAO/VBO)
    // Qui andrebbe il tuo codice di rendering OpenGL

    SDL_GL_SwapWindow(m_window);
}

bool SDLWindow::isOpen() const {
    return m_isOpen;
}
