//
// Created by mattrouss on 2/13/20.
//
#include <fstream>

#include "image.hh"

Image::Image(int w, int h) {
    w_ = w;
    h_ = h;

    pixels_.resize(w);
    for (int i = 0; i < w; i++)
        pixels_[i].resize(h);
}

void Image::dump_ppm(const std::string &output_file) const {
    std::ofstream out(output_file, std::ios::binary);

    out << "P6\n" << w_ << " " << h_ << "\n" << "255\n";
    for (int i = 0; i < w_; i++)
    {
        for (int j = 0; j < h_; j++)
        {
            out.write((char *) &pixels_[i][j].r, 1);
            out.write((char *) &pixels_[i][j].g, 1);
            out.write((char *) &pixels_[i][j].b, 1);
        }
    }
}

Image Image::test_image()
{
    Image im(255, 255);
    for (int i = 0; i < 255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            im.pixels_[i][j].r = i / 2 + j / 2;
            im.pixels_[i][j].g = i;
            im.pixels_[i][j].b = j;
        }
    }

    return im;
}

void Image::set_pixel(int x, int y, Color c) {
    pixels_[x][y] = c;
}

