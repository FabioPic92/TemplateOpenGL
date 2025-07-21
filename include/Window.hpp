#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
    virtual ~Window() = default;

    virtual bool create(const char* title, int width, int height) = 0;
    virtual void destroy() = 0;
    virtual void handleEvents() = 0;
    virtual void render() = 0;    
    virtual bool isOpen() const = 0;
};


#endif