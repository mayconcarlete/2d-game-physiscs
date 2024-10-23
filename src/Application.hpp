#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graphics.hpp"
#include <memory>
class Application {
    private:
        bool running = false;
        std::unique_ptr<Graphics> graphics;
    public:
        Application() = default;
        ~Application() = default;
        bool IsRunning();
        void Setup();
        void Input();
        void Update();
        void Render();
        void Destroy();
};

#endif