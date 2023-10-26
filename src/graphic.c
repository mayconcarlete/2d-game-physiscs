#include "graphic.h"

#include "SDL2/SDL.h"
#include "config.h"

struct AppWindow *New_AppWindow(){
    return (struct AppWindow*)malloc(sizeof(struct AppWindow));
}

void Free_AppWindow(struct AppWindow *this){
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void initialize_window(struct AppWindow *this){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    this->window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    this->renderer = SDL_CreateRenderer(
        this->window,
        -1,
        0
    );
}