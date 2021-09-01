#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"

class triangle: public hittable{

  triangle(){};

  triangle(vec3& aa, vec3&bb, vec3& cc, vec3& nn, shared_ptr<material> mm, float s=1.0)
    : a(aa), b(bb), c(cc), normal(nn), mat_ptr(mm), scale(s){

      e1 = b - a;
      e2 = c - a;

      normal = cross(e1, e2);
      normal = unit_vector(normal);

      d = dot(normal, a);
    }

  virtual bool hit(const ray& r, float tmin, float t_max, hit_record&) const;

  virtual bool bounding_box(float t0, float t1, aabb& box) const;

  vec3 a, b, c;
  vec3 e1, e2;
  vec3 normal;
  float area;
  float scale;
  float d;
  shared_ptr<material> mat_ptr;
};

bool triangle::hit(const ray& r, float tmin, float t_max, hit_record&) const{

  return true;
}

bool triangle::bounding_box(float t0, float t1, aabb& box) const{

  return true;
}

#endif /* TRIANGLE_H */
