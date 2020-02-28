//
// Created by mattrouss on 2/28/20.
//

#pragma once

#include <vector>

#include "math_types.hh"
#include "object.hh"
#include "triangle_index.hh"

using triangles = std::vector<Triangle*>;

struct EnergyPoint
{
    EnergyPoint(const float &energy_, const Vector3 &org_): energy(energy_), org(org_) {}

    float energy_at(const Vector3 &p) const;

    float energy;
    Vector3 org;
};

class Blob {
public:
    Blob(const std::vector<EnergyPoint> &energy_points, float discrt_step,
            float width, float height, float depth, const Vector3 &space_org,
            const Uniform_Texture &texture):
            energy_points_(energy_points),
            discrt_step_(discrt_step),
            width_(width),
            height_(height),
            depth_(depth),
            space_org_(space_org),
            texture_(texture) {}
    float get_potential_at(const Vector3 &p) const;

    triangles march_cubes(float S) const;

private:
    triangles index_to_triangles(int index, const Vector3& org) const;
    Vector3 get_edge_coords(int edge_idx, const Vector3& org) const;

    float discrt_step_, width_, height_, depth_;
    Vector3 space_org_;

    std::vector<EnergyPoint> energy_points_;
    Uniform_Texture texture_;
};



