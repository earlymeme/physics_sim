
#ifndef INCLUDE_COLLISION_H
#define INCLUDE_COLLISION_H

#include <vector>
#include <list>
#include "vec.h"


class collidable {
  public:
    virtual vec3 collision_point(vec3 dir) const = 0;
    virtual ~collidable() {}

    std::vector<vec3> sim_pts;
    std::vector<std::pair<vec3,vec3> > sim_edges;
};

struct simplex_pt {
  vec3 val;
  vec3 a;
  vec3 b;
  simplex_pt(vec3, vec3, vec3);
  simplex_pt();
  bool operator==(const simplex_pt &p);
};

struct epa_tri {
  simplex_pt a, b, c;
  vec3 norm;
  vec3 ab, ac, bc;
  double dist;
  epa_tri(simplex_pt &a, simplex_pt &b, simplex_pt &c);
};

// GJK Implementation
bool collide(const collidable &a, const collidable &b);
bool collide(const collidable &a, const collidable &b, std::vector<simplex_pt> &pts, vec3 &dir);

// EPA Implementation to find collision surface normal.
epa_tri epa(const collidable &one, const collidable &two, std::vector<simplex_pt> &pts);

// Find contact points between two objects.
bool contact_points(collidable &a, collidable &b, std::list<vec3> &a_pts, std::list<vec3> &b_pts, vec3 &sep);


// Exposed for unit testing, should not be used.
bool process_simplex(std::vector<simplex_pt> &pts, vec3 &dir);
std::list<vec3> collision_points(const collidable &a, const vec3 &n, vec3 perp, const vec3 &pt, int samples);


#endif
