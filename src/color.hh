//
// Created by mattrouss on 2/21/20.
//

#pragma once

#include <cstdint>
#include "math_types.hh"

struct Color_Intensity;

struct Color
{
    uint8_t r, g, b;

    Color(uint8_t r_ = 0, uint8_t g_ = 0, uint8_t b_ = 0): r(r_), g(g_), b(b_) {}

    float r_intensity() const;
    float g_intensity() const;
    float b_intensity() const;

    Color_Intensity to_intensity() const;

    friend std::ostream& operator<<(std::ostream &out, Color &c);
};

struct Color_Intensity
{
    float r, g, b;

    Color_Intensity(float r_ = 0, float g_ = 0, float b_ = 0): r(r_), g(g_), b(b_) {}

    Color_Intensity operator+=(const Color_Intensity &l);
    Color_Intensity operator+(const Color_Intensity &l);

    friend Color_Intensity operator*(const float &l, Color_Intensity rhs);

    Color_Intensity& add_diffuse(const float &kd, const Color &obj_color,
                                 const Color_Intensity &light_colors,
                                 const Vector3 &N,
                                 const Vector3 &L);

    Color_Intensity& add_specular(const float &ks,
                                  const float &ns,
                                  const Color_Intensity &light_colors,
                                  const Vector3 &S,
                                  const Vector3 &L);

    Color to_rgb() const;

    friend std::ostream& operator<<(std::ostream &out, Color_Intensity &l);
};

