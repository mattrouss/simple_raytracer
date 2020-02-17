//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include <tuple>

#include "math_types.hh"

class Texture_Material
{
public:
    explicit Texture_Material(float kd = 0, float ks = 0): kd_(kd), ks_(ks) {}

    virtual std::tuple<float, float, Color> get_texture_elms(const Vector3 &p) const = 0;

protected:
    float kd_, ks_;
};

class Uniform_Texture : public Texture_Material
{
public:
    Uniform_Texture(float kd, float ks, const Color &color): Texture_Material(kd, ks), color_(color) {}
    std::tuple<float, float, Color> get_texture_elms(const Vector3 &p) const override;

private:
    Color color_;
};


