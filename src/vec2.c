#include <math.h>
#include <stdlib.h>

#include "vec2.h"

struct Vec2* new_vec2(double x, double y) {
    struct Vec2* vec2 = (struct Vec2*)malloc(sizeof(struct Vec2));
    vec2->x = x;
    vec2->y = y;
    return vec2;
}

void free_vec2(struct Vec2* vec2){
    free(vec2);
}

double magnitude(struct Vec2* vec2){
    return sqrt((vec2->x * vec2->x) + (vec2->y * vec2->y));
}
