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

Vector3 Point3::operator-(const Point3 &p) const {
    return {
            x_ - p.x_,
            y_ - p.y_,
            z_ - p.z_
    };
}

std::ostream& operator<<(std::ostream &out, Point3 &p) {
    return out << "Point3(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")";
}


Vector3 Vector3::operator+(const Vector3 &v) const {
    return {
            x_ + v.x_,
            y_ + v.y_,
            z_ + v.z_
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

Vector3 Vector3::operator/(const float &l) const {
    return {
            x_ / l,
            y_ / l,
            z_ / l
    };
}

float Vector3::length() const {
    return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

float Vector3::dot(const Vector3 &v) const {
    return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

float Vector3::sqr_magnitude() const {
    return this->dot(*this);
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {
            y_ * v.z_ - z_ * v.y_,
            z_ * v.x_ - x_ * v.z_,
            x_ * v.y_ - y_ * v.x_
    };
}

Vector3 Vector3::normalize() {
    return *this / this->length();
}


std::ostream& operator<<(std::ostream &out, Vector3 &vec) {
    return out << "Vector3(" << vec.x_ << ", " << vec.y_ << ", " << vec.z_ << ")";
}

