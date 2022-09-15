#include "Application.h"
#include <iostream>
#include "./Physics/Vec2.h"
#include "./Physics/Contants.h"

bool Application::IsRunning() {
    return running;
}

///////////////////////////////////////////////////////////////////////////////
// Setup function (executed once in the beginning of the simulation)
///////////////////////////////////////////////////////////////////////////////
void Application::Setup() {
    running = Graphics::OpenWindow();
    particle = new Particle(50, 100, 1.0);
    // TODO: setup objects in the scene
}

///////////////////////////////////////////////////////////////////////////////
// Input processing
///////////////////////////////////////////////////////////////////////////////
void Application::Input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// Update function (called several times per second to update objects)
///////////////////////////////////////////////////////////////////////////////
void Application::Update() {
    // todo
    // Check if we are to fast and if so, waste some milliseconds until we reach the MILLISECONDS_PER_FRAME
    int timeToWait = MILLISECONDS_PER_FRAME - (SDL_GetTicks() - this->timePreviousFrame);

    if(timeToWait > 0){
        SDL_Delay(timeToWait);
    }

    this->timePreviousFrame = SDL_GetTicks();

    particle->SetVelocity(1.0, 0.0);
    // particle->AddPosition(particle->GetVelocity());
    particle->GetPosition() += particle->GetVelocity();
}

///////////////////////////////////////////////////////////////////////////////
// Render function (called several times per second to draw objects)
///////////////////////////////////////////////////////////////////////////////
void Application::Render() {
    Graphics::ClearScreen(0xFF056263);
    Graphics::DrawFillCircle(particle->GetXPosition(), particle->GetYPosition(), 4, 0xFFFFFFFF);
    Graphics::RenderFrame();
}

///////////////////////////////////////////////////////////////////////////////
// Destroy function to delete objects and close the window
///////////////////////////////////////////////////////////////////////////////
void Application::Destroy() {
    // TODO: destroy all objects in the scene
    delete particle;
    Graphics::CloseWindow();
}