#include "Application.hpp"
#include "SDL2/SDL.h"
#include <memory>
#include <cstdint>
#include "Physics/Vec2.hpp"
#include "Physics/Particle.hpp"
#include "Physics/Constants.hpp"

bool Application::IsRunning(){
    return running;
}

void Application::Setup(){
    std::uint32_t width = 500;
    std::uint32_t height = 400;
    graphics = std::make_unique<Graphics>(width, height);
    running = graphics->OpenWindow();
    particle = new Particle(50.0f, 100.0f, 1.0f);
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
    static std::uint32_t timePreviousFrame = SDL_GetTicks64();
    const auto waitTime = MILLISECONDS_PER_FRAME - (SDL_GetTicks64() - timePreviousFrame);
    if(waitTime > 0){
        SDL_Delay(waitTime);
    }

    float deltaTime = (SDL_GetTicks64() - timePreviousFrame) / 1000.0f;
    // to protect the code on debugger for example
    if(deltaTime > 0.016){
        deltaTime = 0.016;
    }
    
    timePreviousFrame = SDL_GetTicks64();

    particle->velocity = Vec2(100.0f * deltaTime, 30.0f * deltaTime);
    particle->position += particle->velocity;
}
// std::vector<Vec2> v {Vec2(0,0), Vec2(100, 0), Vec2(100, 100), Vec2(0, 100)};
void Application::Render(){
    graphics->ClearScreen(0xFF056263);
    // Graphics::DrawFillCircle(200, 200, 40, 0xffffffff);
    // graphics->DrawLine(0, 0, 300, 300,0xffffffff );
    // graphics->DrawCircle(particle->position.x, particle->position.y, 4, 3.14, 0xFFFFFFFF);
    graphics->DrawFillCircle(particle->position.x, particle->position.y, 4, 0xFFFFFFFF);
    // graphics->DrawFillRect(200, 200, 100, 100, 0xFFFF0000);
    // graphics->DrawFillPolygon(100, 100, v, 0xFFFFFFFF);
    
    graphics->RenderFrame();
}

void Application::Destroy(){
    delete particle;
    graphics->CloseWindow();
}