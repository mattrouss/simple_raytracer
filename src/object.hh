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
    virtual std::tuple<float, float, float, Color> get_texture_elms(const Vector3 &p) const = 0;
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
    std::tuple<float, float, float, Color> get_texture_elms(const Vector3 &p) const override;

private:
    float r_;
    Vector3 org_;

    Uniform_Texture texture_;
};
