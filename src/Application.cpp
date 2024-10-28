#include "Application.hpp"
#include "SDL2/SDL.h"
#include <memory>
#include <cstdint>
#include <iostream>
#include "Physics/Vec2.hpp"
#include "Physics/Particle.hpp"
#include "Physics/Constants.hpp"

bool Application::IsRunning(){
    return running;
}

void Application::Setup(){
    std::uint32_t width = window_width;
    std::uint32_t height = window_height;
    graphics = std::make_unique<Graphics>(width, height);
    running = graphics->OpenWindow();
    particle = new Particle(50.0f, 0.0f, 1.0f);
    particle->ClearForces();
}

void Application::Input(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                }
                break;
        }
    }
}

void Application::Update(){
    static std::uint32_t timePreviousFrame;
    std::int32_t waitTime = MILLISECONDS_PER_FRAME - (SDL_GetTicks64() - timePreviousFrame);
    if(waitTime > 0){
        SDL_Delay(waitTime);
    }

    float deltaTime = (SDL_GetTicks64() - timePreviousFrame) / 1000.0f;
    // to protect the code on debugger for example
    if(deltaTime > 0.016){
        deltaTime = 0.016;
    }
    timePreviousFrame = SDL_GetTicks64();

    Vec2 wind = Vec2(10.0, 0.0);
    particle->AddForce(wind);
    particle->Integrate(deltaTime);




    // check particle position
    if(particle->position.y - particle->radius <= 0){
        particle->position.y = particle->radius;
        particle->velocity.y *= -0.8;
    } else if(particle->position.y + particle->radius >= window_height){
        particle->position.y = window_height - particle->radius;
        particle->velocity.y *= -0.8;
    }

    if(particle->position.x - particle->radius <= 0){
        particle->position.x = particle->radius;
        particle->velocity.x *= -0.8;
    } else if (particle->position.x + particle->radius >= window_width){
        particle->position.x = window_width - particle->radius;
        particle->velocity.x *= -0.8;
    }
    
}
// std::vector<Vec2> v {Vec2(0,0), Vec2(100, 0), Vec2(100, 100), Vec2(0, 100)};
void Application::Render(){
    graphics->ClearScreen(0xFF056263);
    // Graphics::DrawFillCircle(200, 200, 40, 0xffffffff);
    // graphics->DrawLine(0, 0, 300, 300,0xffffffff );
    // graphics->DrawCircle(particle->position.x, particle->position.y, 4, 3.14, 0xFFFFFFFF);
    graphics->DrawFillCircle(particle->position.x, particle->position.y, particle->radius, 0xFFFFFFFF);
    // graphics->DrawFillRect(200, 200, 100, 100, 0xFFFF0000);
    // graphics->DrawFillPolygon(100, 100, v, 0xFFFFFFFF);
    
    graphics->RenderFrame();
}

void Application::Destroy(){
    delete particle;
    graphics->CloseWindow();
}