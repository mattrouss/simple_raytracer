//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include <vector>

#include "object.hh"
#include "light.hh"
#include "camera.hh"

class Scene {
public:

private:
    std::vector<Object> objects_;
    std::vector<Light> lights_;

    Camera cam_;
};

