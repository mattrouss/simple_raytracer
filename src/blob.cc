//
// Created by mattrouss on 2/28/20.
//

#include "blob.hh"

#define EPSILON 1e-6

float EnergyPoint::energy_at(const Vector3 &p) const {
    float dist = (p - org).magnitude();
    return energy / (dist + EPSILON);
}

float Blob::get_potential_at(const Vector3 &p) const {
    float potential = 0;
    for(auto& energy_point: energy_points_)
        potential += energy_point.energy_at(p);

    return potential;
}

triangles Blob::march_cubes(const float S) const {
    int index;
    triangles triangles;
    Vector3 p = space_org_;
    Vector3 space_dst(space_org_.x() + width_, space_org_.y() + height_ ,space_org_.z() + depth_);
    for (; p.z() < space_dst.z(); p.add_z(discrt_step_)) {
        for (; p.y() < space_dst.y(); p.add_y(discrt_step_)) {
            for (; p.x() < space_dst.x(); p.add_x(discrt_step_)) {
                index = 0;
                if (get_potential_at(p + discrt_step_ * Vector3::diagXYZ()) < S) index |= 1;
                if (get_potential_at(p + discrt_step_ * Vector3::diagYZ()) < S) index |= 2;
                if (get_potential_at(p + discrt_step_ * Vector3::up()) < S) index |= 4;
                if (get_potential_at(p + discrt_step_ * Vector3::diagXY()) < S) index |= 8;
                if (get_potential_at(p + discrt_step_ * Vector3::diagXZ()) < S) index |= 16;
                if (get_potential_at(p + discrt_step_ * Vector3::forward()) < S) index |= 32;
                if (get_potential_at(p) < S) index |= 64;
                if (get_potential_at(p + discrt_step_ * Vector3::right()) < S) index |= 128;

                auto new_triangles = index_to_triangles(index, p);
                triangles.insert(triangles.end(), new_triangles.begin(), new_triangles.end());
            }
        }
    }
    return triangles;
}

triangles Blob::index_to_triangles(int index, const Vector3 &org) const {
    triangles triangles;
    for (int i = 0; i < 15; i+=3)
    {
        int edge0 = trg_index[index][i];
        int edge1 = trg_index[index][i + 1];
        int edge2= trg_index[index][i + 2];
        if (edge0 == -1)
            break;
        Vector3 a = get_edge_coords(edge0, org);
        Vector3 b = get_edge_coords(edge1, org);
        Vector3 c = get_edge_coords(edge2, org);
        triangles.emplace_back(new Triangle(a, b, c, texture_));
    }

    return triangles;
}

Vector3 Blob::get_edge_coords(int edge_idx, const Vector3 &org) const {
    Vector3 edge = org;
    float half_step = discrt_step_ / 2.f;
    switch(edge_idx)
    {
        case 0:
            edge += discrt_step_ * Vector3::diagYZ() + half_step * Vector3::right();
            break;
        case 1:
            edge += discrt_step_ * Vector3::up() + half_step * Vector3::forward();
            break;
        case 2:
            edge += discrt_step_ * Vector3::up() + half_step * Vector3::right();
            break;
        case 3:
            edge += discrt_step_ * Vector3::diagXY() + half_step * Vector3::forward();
            break;
        case 4:
            edge += discrt_step_ * Vector3::forward() + half_step * Vector3::right();
            break;
        case 5:
            edge += half_step * Vector3::forward();
            break;
        case 6:
            edge += half_step * Vector3::right();
            break;
        case 7:
            edge += discrt_step_ * Vector3::right() + half_step * Vector3::forward();
            break;
        case 8:
            edge += discrt_step_ * Vector3::diagXZ() + half_step * Vector3::up();
            break;
        case 9:
            edge += discrt_step_ * Vector3::forward() + half_step * Vector3::up();
            break;
        case 10:
            edge += half_step * Vector3::up();
            break;
        case 11:
            edge += discrt_step_ * Vector3::right() + half_step * Vector3::up();
            break;
    }
    return edge;
}
