#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graphics.hpp"
#include <memory>
#include "Physics/Particle.hpp"
#include <vector>

class Application {
    private:
        bool running = false;
        std::unique_ptr<Graphics> graphics;
        std::vector<std::shared_ptr<Particle>> particles;

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