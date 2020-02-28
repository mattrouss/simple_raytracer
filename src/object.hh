//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include <cstdint>
#include <tuple>

#include "math_types.hh"
#include "textures.hh"

class Object {
public:
    virtual float intersects(const Ray &r) const = 0;
    virtual Vector3 normal_of(const Vector3 &v) const = 0;
    virtual std::tuple<float, float, float, float, Color> get_texture_elms(const Vector3 &p) const = 0;
};

class Sphere : public Object
{
public:
    Sphere(float r, Vector3 org, const Uniform_Texture &texture):
        r_(r),
        org_(org),
        texture_(texture) {}

    float intersects(const Ray &r) const override;
    Vector3 normal_of(const Vector3 &v) const override;
    const Color &get_color() const;
    std::tuple<float, float, float, float, Color> get_texture_elms(const Vector3 &p) const override;

private:
    float r_;
    Vector3 org_;

    Uniform_Texture texture_;
};

class Plane: public Object
{
public:
    Plane(const Vector3 &org, const Vector3 &normal, const Uniform_Texture &texture):
            org_(org),
            normal_(normal),
            texture_(texture) {}

    float intersects(const Ray &r) const override;
    Vector3 normal_of(const Vector3 &v) const override;
    std::tuple<float, float, float, float, Color> get_texture_elms(const Vector3 &p) const override;

private:
    Vector3 org_, normal_;

    Uniform_Texture texture_;

};

class Triangle: public Object
{
public:
    Triangle(const Vector3 &a, const Vector3 &b, const Vector3 &c, const Uniform_Texture &texture):
    a_(a), b_(b), c_(c), texture_(texture)
    {
        normal_ = -1 * (b - a).cross(c - a).normalized();
    }

    float intersects(const Ray &r) const override;
    Vector3 normal_of(const Vector3 &v) const override;
    std::tuple<float, float, float, float, Color> get_texture_elms(const Vector3 &p) const override;

private:
    Vector3 a_, b_, c_, normal_;
    Uniform_Texture texture_;
};
