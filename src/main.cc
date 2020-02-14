#include <iostream>

#include "math_types.hh"
#include "object.hh"
#include "image.hh"

int main(int argc, char* argv[])
{
    /*
    Point3 p = Point3(1, 2, 3);
    Point3 q = Point3(1, 2, 3);
    p = p + q;
    std::cout << p << "\n";

    Vector3 v = Vector3(2, 4, 6);
    std::cout << v.dot(v) << "\n";
    */
    Image im = Image::test_image();
    Sphere sp(15, {10, 10, 10});

    Ray r({0, 0, 0}, {1, 1, 1});

    std::cout << sp.intersects(r);

    return 0;
}
