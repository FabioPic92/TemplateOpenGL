#include "Application.hpp"
#include <iostream>

Application::Application()
: m_running(false) 
{
}

bool Application::init(){
    m_running = true;
    return m_running;
}

void Application::run() {
    if (!m_running) {
        std::cerr << "Application not initialized. Call init() first." << std::endl;
        return;
    }

    std::cout << "Application is running..." << std::endl;

    while (m_running) {
        for (const auto& window : m_windows) {
            window->handleEvents();
        }

        bool allWindowsClosed = true;
        for (const auto& window : m_windows) {
            if (window->isOpen()) {
                allWindowsClosed = false;
                break;
            }
        }

        if (allWindowsClosed) {
            m_running = false;
        }

        for (const auto& window : m_windows) {
            if (window->isOpen()) {
                window->render();
            }
        }
    }
}

void Application::shutdown() {
    std::cout << "Application shutting down..." << std::endl;
    m_windows.clear(); 

    SDL_Quit();
    std::cout << "SDL Terminated globally." << std::endl;
    m_running = false;
}

Application::~Application() {
    shutdown();
}

void Application::addWindow(std::unique_ptr<Window> window) {
    m_windows.push_back(std::move(window));
}