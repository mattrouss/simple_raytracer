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
    virtual Vector3 normal_of(Point3 &p) = 0;
    virtual std::tuple<float, float> get_texture_elms(Point3 &p) = 0;
};

class Sphere : public Object
{
public:
    Sphere(float r, Point3 org, const Uniform_Texture &texture = Uniform_Texture()):
        r_(r),
        org_(org),
        texture_(texture) {}

    float intersects(const Ray &r) const override;
    Vector3 normal_of(Point3 &p) override;
    std::tuple<float, float> get_texture_elms(Point3 &p) override;

private:
    float r_;
    Point3 org_;

    Uniform_Texture texture_;
};
