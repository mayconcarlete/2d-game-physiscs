#include "Application.hpp"
#include "SDL2/SDL.h"
#include <memory>
#include <cstdint>
#include "Physics/Vec2.hpp"
#include "Physics/Particle.hpp"

bool Application::IsRunning(){
    return running;
}

void Application::Setup(){
    std::uint32_t width = 500;
    std::uint32_t height = 400;
    graphics = std::make_unique<Graphics>(width, height);
    running = graphics->OpenWindow();
    auto particle = std::make_unique<Particle>(100.0f, 200.0f, 10.0f);
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

}
// std::vector<Vec2> v {Vec2(0,0), Vec2(100, 0), Vec2(100, 100), Vec2(0, 100)};
void Application::Render(){
    graphics->ClearScreen(0xFF056263);
    // Graphics::DrawFillCircle(200, 200, 40, 0xffffffff);
    // graphics->DrawLine(0, 0, 300, 300,0xffffffff );
    // graphics->DrawCircle(300, 300, 30, 3.14, 0xFFFFFFFF);
    // graphics->DrawFillCircle(200, 200, 20, 0xFFFF0000);
    // graphics->DrawFillRect(200, 200, 100, 100, 0xFFFF0000);
    // graphics->DrawFillPolygon(100, 100, v, 0xFFFFFFFF);
    
    graphics->RenderFrame();
}

void Application::Destroy(){
    graphics->CloseWindow();
}