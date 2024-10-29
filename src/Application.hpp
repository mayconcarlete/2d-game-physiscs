#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <vector>

#include "Graphics.hpp"
#include "Physics/Vec2.hpp"
#include "Physics/Particle.hpp"

class Application {
    private:
        bool running = false;
        std::unique_ptr<Graphics> graphics;
        std::vector<std::shared_ptr<Particle>> particles;
        Vec2 pushForce;
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