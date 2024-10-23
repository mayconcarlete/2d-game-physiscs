#include "Application.hpp"
#include "SDL2/SDL.h"
#include <memory>
#include <cstdint>

bool Application::IsRunning(){
    return running;
}

void Application::Setup(){
    std::uint32_t width = 500;
    std::uint32_t height = 400;
    graphics = std::make_unique<Graphics>(width, height);
    running = graphics->OpenWindow();
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

void Application::Render(){
    graphics->ClearScreen(0xFF056263);
    // Graphics::DrawFillCircle(200, 200, 40, 0xffffffff);
    // graphics->DrawLine(0, 0, 300, 300,0xffffffff );
    // graphics->DrawCircle(300, 300, 30, 3.14, 0xFFFFFFFF);
    // graphics->DrawFillCircle(200, 200, 20, 0xFFFF0000);
    graphics->DrawRect(200, 200, 100, 100, 0xFFFF0000);
    graphics->RenderFrame();
}

void Application::Destroy(){
    graphics->CloseWindow();
}