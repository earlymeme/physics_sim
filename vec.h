
#ifndef INCLUDE_VEC_H
#define INCLUDE_VEC_H

#include <ostream>

class vec3 {
  public:
    double x;
    double y;
    double z;

  public:
    vec3();
    vec3(const vec3 &v);
    vec3(double x, double y, double z);

    double dot(const vec3& v2) const;
    vec3& norm();
    double len() const;
    double lenSq() const;
    vec3& negate();

    bool operator==(const vec3& v) const;
    bool operator!=(const vec3& v) const;
    bool operator<(const vec3& v) const;
    vec3& operator+=(const vec3& v);
    vec3& operator-=(const vec3& v);
    vec3& operator*=(double factor);
    vec3 operator*(const vec3& v) const;
    vec3 operator*(double factor) const;
    vec3 operator-(const vec3& v) const;
    vec3 operator+(const vec3& v) const;

    friend std::ostream& operator<<(std::ostream&,const vec3&);

};

std::ostream& operator<<(std::ostream& s, const vec3& v);

#endif
