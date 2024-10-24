#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graphics.hpp"
#include <memory>
#include "Physics/Particle.hpp"
class Application {
    private:
        bool running = false;
        std::unique_ptr<Graphics> graphics;
        std::unique_ptr<Particle> particle;
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