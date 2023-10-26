#include <stdio.h>
#include "SDL2/SDL.h"

#include "config.h"
#include "vec2.h"
#include "graphic.h"

SDL_Window* window; 
SDL_Renderer* renderer;
struct Vec2* vec2; 

void setup(){
    vec2 = New_Vec2(100, 100);    
}

void update(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, 200, 200);
    SDL_RenderPresent(renderer);
}

void render(){}

int main(){
    struct Vec2* vec2 = New_Vec2(3, 4);
    struct Vec2 vAdd, vSub;
    vAdd.x = 1;
    vAdd.y = 1;
    vSub.x = 4;
    vSub.y = 5;

    // add(vec2, vAdd);
    // subtraction(vec2, vSub);
    // printf("X: %.2f Y: %.2f magnitude: %.2f\n", vec2->x, vec2->y, magnitude(vec2));
    // scale(vec2, -1);
    // struct Vec2* vec_b = add_static(&vAdd, &vSub);
    struct Vec2* vec_b = Sub_Vec2_Static(&vAdd, &vSub);
    struct Vec2* vec_c = scale_static(&vSub, 3);
    double dot = dot_product(&vAdd, &vSub);
    printf("Dot: %.2f", dot);
    Print_Vec2(vec_c);

    Free_Vec2(vec2);
    Free_Vec2(vec_b);
    Free_Vec2(vec_c);

    struct AppWindow *app = New_AppWindow();
    initialize_window(app);

    setup();
    
    while(1){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:{
                    goto out;
                }
                break;
            
            default:
                break;
            }
        }

        update();
        render();
    }
    out:
        Free_AppWindow(app);
        return 0;
}