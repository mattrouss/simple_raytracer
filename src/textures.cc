//
// Created by mattrouss on 2/14/20.
//

#include "textures.hh"


std::tuple<float, float> Uniform_Texture::get_texture_elms(const Point3 &p) const {
    return std::make_tuple(kd_, ks_);
}
