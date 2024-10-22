#ifndef VEC2_H
#define VEC2_H

class Vec2{
    public:
        float x;
        float y;

        Vec2();
        Vec2(float x, float y);
        ~Vec2() = default;
        void Print() const;

        void Add(const Vec2& v);
        void Sub(const Vec2& v);
        void Scale(const float n);
        Vec2 Rotate(const float angle) const; // angle in radians;

        float Magnitude() const;
        float MagnitudeSquared() const;

        Vec2& Normalize(); // Normalize its own vector
        Vec2 UnitVector() const; // return a new vector
        Vec2 Normal() const; // Perpendicular

        float Dot(const Vec2& v) const;
        float Cross(const Vec2& v) const;

        Vec2& operator = (const Vec2& v); // v1 = v2
        bool operator == (const Vec2& v) const; // v1 == v2
        bool operator != (const Vec2& v) const; // v1 != v2

        Vec2 operator + (const Vec2& v) const; // v = v1 + v2
        Vec2 operator - (const Vec2& v) const; // v = v1 - v2
        Vec2 operator * (const float n) const; // v = v1 * v2
        Vec2 operator / (const float n) const; // v = v1 / v2

        Vec2 operator - (); // -v1
};


#endif