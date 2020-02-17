//
// Created by mattrouss on 2/13/20.
//
#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "math_types.hh"

class Image {
public:
    Image(int w, int h);

    void set_pixel(int x, int y, Color c);
    void dump_ppm(const std::string &output_file) const;

    static Image test_image();

private:
    int w_, h_;
    std::vector<std::vector<Color>> pixels_;
};

