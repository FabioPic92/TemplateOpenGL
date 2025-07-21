#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.hpp"
#include "SDLWindow.hpp"
#include <vector>     
#include <memory> 

class Application {
public:

    Application();
    ~Application();

    bool init();
    void run();
    void shutdown();

    void addWindow(std::unique_ptr<Window> window);

private:

    std::vector<std::unique_ptr<Window>> m_windows;

    bool m_running;
};

#endif