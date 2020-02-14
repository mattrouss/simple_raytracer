//
// Created by mattrouss on 2/13/20.
//
#ifndef TP1_RAYTRACER_IMAGE_HH
#define TP1_RAYTRACER_IMAGE_HH

#include <cstdint>
#include <vector>
#include <string>

#include "math_types.hh"

class Image {
    public:
    Image(int w, int h);

    void dump_ppm(const std::string &output_file) const;

    static Image test_image();

    private:
        int w_, h_;
        std::vector<std::vector<Color>> pixels_;
};

#endif //TP1_RAYTRACER_IMAGE_HH
