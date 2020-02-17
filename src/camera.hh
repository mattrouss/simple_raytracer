//
// Created by mattrouss on 2/14/20.
//

#pragma once

#include "math_types.hh"

class Camera {
public:
    Camera(Point3 org, Point3 dst, Vector3 up, float fov_x, float fov_y, float z_min):
    org_(org), dst_(dst), up_(up), fov_x_(fov_x), fov_y_(fov_y), z_min_(z_min) {}


private:
    Point3 org_, dst_;
    Vector3 up_;
    float fov_x_, fov_y_, z_min_;
};



