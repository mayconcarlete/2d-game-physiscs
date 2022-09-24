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
    Particle* smallBall = new Particle(500, 0, 1.0);
    Particle* bigBall = new Particle(500, 0, 3.0);
    smallBall->radius = 4;
    bigBall->radius = 12;
    this->particles.push_back(smallBall);
    this->particles.push_back(bigBall);

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
    Vec2 wind = Vec2(3.0, 0.0);

    for(auto particle: particles){
        Vec2 weight = Vec2(0.0, particle->mass * 9.8 * PIXELS_PER_METER);
        particle->AddForce(wind);
        particle->AddForce(weight);
    }

    for(auto particle: this->particles){
        particle->UpdateVelocity(deltaTime);
    }
}

///////////////////////////////////////////////////////////////////////////////
// Render function (called several times per second to draw objects)
///////////////////////////////////////////////////////////////////////////////
void Application::Render() {
    Graphics::ClearScreen(0xFF056263);
    for(auto particle: this->particles){
        Graphics::DrawFillCircle(particle->GetXPosition(), particle->GetYPosition(), particle->radius, 0xFFFFFFFF);
    }
    Graphics::RenderFrame();
}

///////////////////////////////////////////////////////////////////////////////
// Destroy function to delete objects and close the window
///////////////////////////////////////////////////////////////////////////////
void Application::Destroy() {
    // TODO: destroy all objects in the scene
    for(auto particle: this->particles){
        delete particle;
    }
    Graphics::CloseWindow();
}