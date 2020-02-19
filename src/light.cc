//
// Created by mattrouss on 2/14/20.
//

#include "light.hh"

Light_Intensity Light::intensity() const {
    return intensity_;
}

Vector3 Point_Light::direction_from(const Vector3 &v) const {
    return (org_ - v).normalized();
}
