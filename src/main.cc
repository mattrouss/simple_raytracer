#include <iostream>

#include "math_types.hh"
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
    im.dump_ppm("out.txt");

    return 0;
}
