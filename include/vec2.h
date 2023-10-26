#ifndef VEC2_H
#define VEC2_H

struct  Vec2 {
    double x;
    double y;
};

struct Vec2 *New_Vec2(double x, double y);
void Free_Vec2(struct Vec2 *this);
void Print_Vec2(struct Vec2 *this);

double Magnitude(struct Vec2 *this);

void Add_Vec2(struct Vec2 *this, struct Vec2 v);
struct Vec2 *Add_Vec2_Static(struct Vec2 *v1, struct Vec2 *v2);

void Sub_Vec2(struct Vec2 *this, struct Vec2 v);
struct Vec2 *Sub_Vec2_Static(struct Vec2 *v1, struct Vec2 *v2);

void Scale_Vec2(struct Vec2 *this, double number);
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