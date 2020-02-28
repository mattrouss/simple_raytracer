#include <iostream>
#include <cmath>
#include <chrono>

#include "math_types.hh"
#include "object.hh"
#include "image.hh"
#include "camera.hh"
#include "scene.hh"
#include "blob.hh"

int main(int argc, char* argv[])
{
    float z_min = 1.f;
    float fov_x = 1.3f;
    float fov_y = 1.3f;
    Camera c({0, 0, 0}, {0, 0, z_min}, Vector3::up(), fov_x, fov_y, z_min);

    Scene s(c, 1024, 1024);

    s.add_light_source(new Point_Light(50.f, Color_Intensity(1, 1, 1), Vector3(0, 20, 0)));
    s.add_light_source(new Point_Light(20.f, Color_Intensity(1, 1, 1), Vector3(10, 3, 3)));
    Uniform_Texture ut_pink(0.3, 0.6, 5, 0.1, Color(255, 0, 150));
    Uniform_Texture ut_red(0.7, 0.2, 3, 0.05, Color(200, 0, 0));
    Uniform_Texture ut_yellow(0.4, 0.4, 6, 0.5, Color(200, 200, 0));
    Uniform_Texture ut_green(0.5, 0.4, 5, 0.1, Color(0, 200, 0));
    Uniform_Texture ut_blue(0.5, 0.4, 4, 0.1, Color(0, 0, 200));
    Uniform_Texture ut_gray(0.7, 0.5, 8, 0.2, Color(100, 100, 100));
    s.add_object(new Plane({15, 0, 0}, {-1, 0, 0}, ut_pink));
    s.add_object(new Plane({-15, 0, 0}, {1, 0, 0}, ut_blue));
    s.add_object(new Plane({0, -5, 0}, {0, 1, 0}, ut_gray));
    s.add_object(new Plane({0, 0, 40}, {0, 0, -1}, ut_gray));
    /*
    s.add_object(new Sphere(2, {0, -3, 14}, ut_pink));
    s.add_object(new Sphere(2, {-5, -3, 10}, ut_green));
    s.add_object(new Sphere(3, {4, -1, 17}, ut_red));
    s.add_object(new Sphere(1, {-5, 5, 15}, ut_gray));
    s.add_object(new Sphere(1, {4, -3, 10}, ut_blue));
    */

    std::vector<EnergyPoint> energy_points;
    energy_points.emplace_back(EnergyPoint(100, Vector3(0, 0, 30)));
    s.add_blob(Blob(energy_points, 0.5f, 40, 40, 20, Vector3(-20, 0, 20), ut_blue));
    s.init_blobs(10);
    auto start = std::chrono::high_resolution_clock::now();
    Image im = s.gen_img();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Image gen time: " << duration.count() << "ms" << std::endl;
    im.dump_ppm("out.ppm");
    return 0;
}
