//
// Created by mattrouss on 2/14/20.
//

#include "light.hh"

Color Light::color() const {
    return color_;
}

Vector3 Point_Light::origin() const {
    return org_;
}
