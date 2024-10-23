#define SDL_MAIN_HANDLED
#include <iostream>
#include "Application.hpp"

int main(int argc, char* argv[]){
    Application app;
    app.Setup();

    while(app.IsRunning()){
        app.Input();
        // app.Update();
        app.Render();

    }

    app.Destroy();

    return EXIT_SUCCESS;
}