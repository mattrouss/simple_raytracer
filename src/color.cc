//
// Created by mattrouss on 2/21/20.
//

#include "color.hh"

std::ostream &operator<<(std::ostream &out, Color &c) {
    return out << "Color(r=" << unsigned(c.r) << ", g=" << unsigned(c.g) << ", b=" << unsigned(c.b) << ")";
}

float Color::r_intensity() const {
    return (float) r / 255.f;
}

float Color::g_intensity() const {
    return (float) g / 255.f;
}

float Color::b_intensity() const {
    return (float) b / 255.f;
}

Color_Intensity Color::to_intensity() const {
    return {
            r_intensity(),
            g_intensity(),
            b_intensity()
    };
}

Color Color_Intensity::to_rgb() const {
    return {
            (uint8_t)std::clamp<float>(r * 255, 0, 255),
            (uint8_t)std::clamp<float>(g * 255, 0, 255),
            (uint8_t)std::clamp<float>(b * 255, 0, 255),
    };
}

Color_Intensity Color_Intensity::operator+=(const Color_Intensity &l) {
    r += l.r;
    g += l.g;
    b += l.b;
    return *this;
}

Color_Intensity Color_Intensity::operator+(const Color_Intensity &l) {
    *this += l;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Color_Intensity &l) {
    return out << "Color_Intensity(r=" << l.r << ", g=" << l.g << ", b=" << l.b << ")";
}

Color_Intensity& Color_Intensity::add_diffuse(const float &kd,
                                              const Color &obj_color,
                                              const Color_Intensity &light_colors,
                                              const Vector3 &N,
                                              const Vector3 &L) {
    float dot = kd * std::max(N.dot(L), 0.f);
    r += obj_color.r_intensity() * light_colors.r * dot;
    g += obj_color.g_intensity() * light_colors.g * dot;
    b += obj_color.b_intensity() * light_colors.b * dot;
    return *this;
}

Color_Intensity& Color_Intensity::add_specular(const float &ks, const float &ns,
                                               const Color_Intensity &light_colors,
                                               const Vector3 &S,
                                               const Vector3 &L) {
    float dot = std::max(S.dot(L), 0.f);
    dot = ks * powf(dot, ns);
    r +=  light_colors.r * dot;
    g +=  light_colors.g * dot;
    b +=  light_colors.b * dot;
    return *this;
}

Color_Intensity operator*(const float &l, Color_Intensity rhs) {
    rhs.r *= l;
    rhs.g *= l;
    rhs.b *= l;
    return rhs;
}

