#ifndef GRAPHIC_C
#define GRAPHIC_C

#include "SDL2/SDL.h"

struct AppWindow {
    SDL_Window* window; 
    SDL_Renderer* renderer;

};

struct AppWindow *New_AppWindow();
void Free_AppWindow(struct AppWindow *this);

void initialize_window(struct AppWindow *this);

#endif