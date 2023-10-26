#include <stdio.h>
#include "SDL2/SDL.h"

#include "config.h"
#include "vec2.h"

SDL_Window* window; 
SDL_Renderer* renderer;
struct Vec2* vec2; 

void setup(){
    vec2 = new_vec2(100, 100);    
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
    struct Vec2* vec2 = new_vec2(3, 4);
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
    struct Vec2* vec_b = subtraction_static(&vAdd, &vSub);
    struct Vec2* vec_c = scale_static(&vSub, 3);
    double dot = dot_product(&vAdd, &vSub);
    printf("Dot: %.2f", dot);
    print_vec(vec_c);

    free_vec2(vec2);
    free_vec2(vec_b);
    free_vec2(vec_c);

    // struct Vec2* vec2 = new_vec2(3,4);  


    // add(vec2,vAdd);
    // printf("after Adding x: %.2f y: %.2f\n", vec2->x, vec2->y);

    // subtraction(vec2, vSub);
    // printf("after subtracting x: %.2f y: %.2f", vec2->x, vec2->y);
    // SDL_Init(SDL_INIT_EVERYTHING);
    // window = SDL_CreateWindow(
    //     WINDOW_TITLE,
    //     SDL_WINDOWPOS_CENTERED,
    //     SDL_WINDOWPOS_CENTERED,
    //     WINDOW_WIDTH,
    //     WINDOW_HEIGHT,
    //     SDL_WINDOW_SHOWN
    // );

    // renderer = SDL_CreateRenderer(
    //     window,
    //     -1,
    //     0
    // );

    // setup();
    
    // while(1){
    //     SDL_Event event;
    //     while(SDL_PollEvent(&event)){
    //         switch (event.type){
    //             case SDL_QUIT:{
    //                 goto out;
    //             }
    //             break;
            
    //         default:
    //             break;
    //         }
    //     }

    //     update();
    //     render();
    // }
    // out:
    //     SDL_DestroyRenderer(renderer);
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return 0;
    return 0;
}