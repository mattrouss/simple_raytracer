#pragma once

#include <ostream>
#include <cstdint>
#include <cmath>

struct Color
{
    uint8_t r, g, b;

    Color(uint8_t r_ = 0, uint8_t g_ = 0, uint8_t b_ = 0): r(r_), g(g_), b(b_) {}

    friend std::ostream& operator<<(std::ostream &out, Color &c);
};

class Vector3
{
public:
    Vector3(float x, float y, float z): x_(x), y_(y), z_(z) {}

    Vector3 operator+(const Vector3 &v) const;
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator*(const float &l) const;
    Vector3 operator/(const float &l) const;

    float length() const;

    friend std::ostream& operator<<(std::ostream &out, Vector3 &vec);

    float dot(const Vector3 &v) const;
    float sqr_magnitude() const;
    Vector3 cross(const Vector3 &v) const;

    Vector3 normalize();

private:
    float x_, y_, z_;
};

class Point3
{
public:
    Point3(float x, float y, float z): x_(x), y_(y), z_(z) {}

    Vector3 operator+(const Point3 &p) const;
    Vector3 operator-(const Point3 &p) const;

    friend std::ostream& operator<<(std::ostream &out, Point3 &p);

private:
    float x_, y_, z_;
};

struct Ray
{
    Point3 org;
    Vector3 dir;

    Ray(const Point3 &org_, const Vector3 &dir_): org(org_), dir(dir_) {}
};

