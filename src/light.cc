//
// Created by mattrouss on 2/14/20.
//

#include "light.hh"

Color Light_Intensity::to_rgb() const {
    return {
            (uint8_t)std::clamp<float>(r * 255, 0, 255),
            (uint8_t)std::clamp<float>(g * 255, 0, 255),
            (uint8_t)std::clamp<float>(b * 255, 0, 255),
    };
}

Light_Intensity Light_Intensity::operator+=(const Light_Intensity &l) {
    r += l.r;
    g += l.g;
    b += l.b;
    return *this;
}

Light_Intensity Light_Intensity::operator+(const Light_Intensity &l) {
    *this += l;
    return *this;
}



std::ostream &operator<<(std::ostream &out, Light_Intensity &l) {
    return out << "Light_Intensity(r=" << l.r << ", g=" << l.g << ", b=" << l.b << ")";
}

Light_Intensity Light::intensity() const {
    return intensity_;
}

Vector3 Point_Light::direction_from(const Vector3 &v) const {
    return (org_ - v).normalized();
}

Vector3 Point_Light::position() const {
    return org_;
}
