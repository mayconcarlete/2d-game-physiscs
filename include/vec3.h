#ifndef VEC3_H
#define VEC3_H

struct Vec3 {
    double x;
    double y;
    double z;
};

struct Vec3 *new_vec3(double x, double y, double z);
void free_vec3(struct Vec3 *this);


#endif