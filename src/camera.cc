//
// Created by mattrouss on 2/14/20.
//

#include "camera.hh"

Vector3 Camera::origin() const {
    return org_;
}

Vector3 Camera::target() const {
    return target_;
}

float Camera::fov_x() const {
    return fov_x_;
}

float Camera::fov_y() const {
    return fov_y_;
}

float Camera::z_min() const {
    return z_min_;
}
