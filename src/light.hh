//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include "math_types.hh"

class Light {
public:
    explicit Light(const Color &color): color_(color) {}

    virtual Vector3 origin() const = 0;
    Color color() const;
protected:
    Color color_;
};

class Point_Light: public Light
{
public:
    Point_Light(const Color &color, const Vector3 &org): Light(color), org_(org) {}

    Vector3 origin() const override;
private:
    Vector3 org_;
};
