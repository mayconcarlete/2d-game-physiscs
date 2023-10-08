#include <stdio.h>
#include "vec2.h"

int main(){
    struct Vec2* vec2 = new_vec2(3,4);    
    printf("X: %.2f Y: %.2f magnitude: %.2f\n", vec2->x, vec2->y, magnitude(vec2));
    return 0;
}