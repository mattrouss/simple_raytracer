#include "math_types.hh"



std::ostream &operator<<(std::ostream &out, Color &c) {
    return out << "Color(r=" << unsigned(c.r) << ", g=" << unsigned(c.g) << ", b=" << unsigned(c.b) << ")";
}


Vector3 Point3::operator+(const Point3 &p) const {
    return {
        x_ + p.x_,
        y_ + p.y_,
        z_ + p.z_
    };
}

Vector3 Point3::operator+(const Vector3 &v) const {
    return {
            x_ + v.x(),
            y_ + v.y(),
            z_ + v.z()
    };
}

Vector3 Point3::operator-(const Point3 &p) const {
    return {
            x_ - p.x_,
            y_ - p.y_,
            z_ - p.z_
    };
}

float Point3::x() const {
    return x_;
}

float Point3::y() const {
    return y_;
}

float Point3::z() const {
    return z_;
}

std::ostream& operator<<(std::ostream &out, const Point3 &p) {
    return out << "Point3(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")";
}


Vector3 Vector3::operator+(const Vector3 &v) const {
    return {
            x_ + v.x_,
            y_ + v.y_,
            z_ + v.z_
    };
}

Vector3 Vector3::operator+(const Point3 &p) const {
    return {
            x_ + p.x(),
            y_ + p.y(),
            z_ + p.z()
    };
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {
        x_ - v.x_,
        y_ - v.y_,
        z_ - v.z_
    };
}

Vector3 Vector3::operator*(const float &l) const {
    return {
            x_ * l,
            y_ * l,
            z_ * l
    };
}

Vector3 operator*(const float &l, const Vector3 &v) {
    return {
            v.x_ * l,
            v.y_ * l,
            v.z_ * l
    };
}

Vector3 Vector3::operator/(const float &l) const {
    return {
            x_ / l,
            y_ / l,
            z_ / l
    };
}

float Vector3::x() const {
    return x_;
}

float Vector3::y() const {
    return y_;
}

float Vector3::z() const {
    return z_;
}

float Vector3::dot(const Vector3 &v) const {
    return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

float Vector3::sqr_magnitude() const {
    return this->dot(*this);
}

float Vector3::magnitude() const {
    return std::sqrt(sqr_magnitude());
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {
            y_ * v.z_ - z_ * v.y_,
            z_ * v.x_ - x_ * v.z_,
            x_ * v.y_ - y_ * v.x_
    };
}

Vector3 Vector3::normalize() const {
    Vector3 copy = *this;
    copy = copy / magnitude();
    return copy;
}


std::ostream& operator<<(std::ostream &out, const Vector3 &vec) {
    return out << "Vector3(" << vec.x_ << ", " << vec.y_ << ", " << vec.z_ << ")";
}

Vector3 Vector3::up() {
    return Vector3(0, 1, 0);
}

Vector3 Vector3::down() {
    return Vector3(0, -1, 0);
}

Vector3 Vector3::left() {
    return Vector3(-1, 0, 0);
}

Vector3 Vector3::right() {
    return Vector3(1, 0, 0);
}

Vector3 Vector3::forward() {
    return Vector3(0, 0, 1);
}

Vector3 Vector3::backward() {
    return Vector3(0, 0, -1);
}

std::ostream &operator<<(std::ostream &out, const Ray &r) {

    out << "Ray (Origin: " << r.org;
    out << ", Direction: " << r.dir << ")" << std::endl;
    return out;
}
