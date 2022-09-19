#include "Application.h"
#include <iostream>
#include "./Physics/Vec2.h"
#include "./Physics/Constants.h"
#include "./Graphics.h"

bool Application::IsRunning() {
    return running;
}

///////////////////////////////////////////////////////////////////////////////
// Setup function (executed once in the beginning of the simulation)
///////////////////////////////////////////////////////////////////////////////
void Application::Setup() {
    running = Graphics::OpenWindow();
    particle = new Particle(500, 0, 1.0);
    particle->radius = 4;
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
    // move timePreviousFrame to static.
    static int timePreviousFrame;
    int timeToWait = MILLISECONDS_PER_FRAME - (SDL_GetTicks() - timePreviousFrame);

    if(timeToWait > 0){
        SDL_Delay(timeToWait);
    }

    float deltaTime = (SDL_GetTicks() - timePreviousFrame) / 1000.0f;
    if(deltaTime > 0.01){
        deltaTime = 0.01;
    }
    timePreviousFrame = SDL_GetTicks();

    particle->acceleration.x = 2.0 * PIXELS_PER_METER;
    particle->acceleration.y = 9.8 * PIXELS_PER_METER;

    particle->velocity += particle->acceleration * deltaTime;
    particle->position += particle->velocity * deltaTime;

    if(particle->position.x - particle->radius <=0) {
        particle->position.x = particle->radius;
        particle->velocity.x *= -0.5;
    } else if(particle->position.x + particle->radius >= Graphics::Width()){
        particle->position.x = Graphics::Width() - particle->radius;
        particle->velocity.x *= -0.5;
    }

    if(particle->position.y - particle->radius <= 0 ){
        particle->position.y = particle->radius;
        particle->velocity.y *= -0.5;
    } else if (particle->position.y + particle->radius >= Graphics::Height()){
        particle->position.y = Graphics::Height() - particle->radius;
        particle->velocity.y *= -0.5;
    }


}

///////////////////////////////////////////////////////////////////////////////
// Render function (called several times per second to draw objects)
///////////////////////////////////////////////////////////////////////////////
void Application::Render() {
    Graphics::ClearScreen(0xFF056263);
    Graphics::DrawFillCircle(particle->GetXPosition(), particle->GetYPosition(), particle->radius, 0xFFFFFFFF);
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