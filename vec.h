
#include <ostream>

class vec3 {
  private:
    double x;
    double y;
    double z;

  public:
    vec3();
    vec3(double x, double y, double z);

    double dot(const vec3& v2);
    vec3& norm();
    double len();
    double lenSq();
    vec3& negate();

    bool operator==(const vec3& v);
    bool operator!=(const vec3& v);
    vec3& operator+=(const vec3& v);
    vec3& operator-=(const vec3& v);
    vec3& operator*=(double factor);
    vec3 operator*(const vec3& v);
    vec3 operator*(double factor);
    vec3 operator-(const vec3& v);
    vec3 operator+(const vec3& v);

    friend std::ostream& operator<<(std::ostream&,vec3&);

};

std::ostream& operator<<(std::ostream& s, vec3& v);

