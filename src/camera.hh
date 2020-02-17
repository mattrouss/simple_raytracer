//
// Created by mattrouss on 2/14/20.
//

#pragma once

#include "math_types.hh"

class Camera {
public:
    Camera(Vector3 org, Vector3 target, Vector3 up, float fov_x, float fov_y, float z_min):
    org_(org), target_(target), up_(up), fov_x_(fov_x), fov_y_(fov_y), z_min_(z_min) {}

    Vector3 origin() const;
    Vector3 target() const;
    float fov_x() const;
    float fov_y() const;
    float z_min() const;

private:
    Vector3 org_, target_;
    Vector3 up_;
    float fov_x_, fov_y_, z_min_;
};



