#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <vector>

#include "Graphics.hpp"
#include "Physics/Vec2.hpp"
#include "Physics/Particle.hpp"
#include "SDL2/SDL.h"

class Application {
    private:
        bool m_running = false;
        Graphics* m_graphics;
        std::vector<Particle*> m_particles;
        Vec2 pushForce;
        SDL_Rect liquid;
        
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