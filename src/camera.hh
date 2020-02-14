//
// Created by mattrouss on 2/14/20.
//

#pragma once

#include "math_types.hh"

class Camera {

private:
    Point3 org_, dst_;
    Vector3 up_;
    float fov_x, fov_y, z;
};



