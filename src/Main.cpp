#include <iostream>

#include "Graphics.hpp"

int main(int argc, char* argv[]){
    // Application app;
    // app.Setup();

    // while(app.IsRunning()){
    //     app.Input();
    //     app.Update();
    //     app.Render();
    // }

    // app.Destroy();
    auto graphics = new Graphics(400, 500);
    graphics->OpenWindow();
    delete graphics;


    return EXIT_SUCCESS;
}