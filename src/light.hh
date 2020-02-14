//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include "math_types.hh"

class Light {
protected:
    float intensity_;
};

class Point_Light: public Light
{
private:
    Point3 org_;
};
