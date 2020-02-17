//
// Created by mattrouss on 2/14/20.
//

#include "textures.hh"


std::tuple<float, float, Color> Uniform_Texture::get_texture_elms(const Vector3 &p) const {
    return std::make_tuple(kd_, ks_, color_);
}
