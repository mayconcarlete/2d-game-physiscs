#ifndef VEC2_H
#define VEC2_H

struct  Vec2 {
    double x;
    double y;
};

struct Vec2 *new_vec2(double x, double y);
void free_vec2(struct Vec2 *this);
void print_vec(struct Vec2 *this);

double magnitude(struct Vec2 *this);

void add(struct Vec2 *this, struct Vec2 v);
struct Vec2 *add_static(struct Vec2 *v1, struct Vec2 *v2);

void subtraction(struct Vec2 *this, struct Vec2 v);
struct Vec2 *subtraction_static(struct Vec2 *v1, struct Vec2 *v2);

void scale(struct Vec2 *this, double number);
struct Vec2 *scale_static(struct Vec2 *this, double number);

/*
*****Dot Product or Scalar product*****
Pense como se fosse o quão alinhado os vetores estão, ou quanta "sombra" o vetor2 faz sobre o vetor1.
Se eles forem paralelos o valor é 1.
Se eles forem perpendiculares o valor é 0;
Se eles forem contrarios(negativos) o valor vai tendendo para -1.
*/
double dot_product(struct Vec2 *v1, struct Vec2 *v2);

#endif