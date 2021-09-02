#ifndef TRIANGLE_H
#define TRIANGLE_H

// #include "aarect.h"
#include "hittable.h"

class triangle: public hittable{
  public:

    triangle(){};

    triangle(vec3& aa, vec3&bb, vec3& cc, vec3& nn, shared_ptr<material> mm, double s=1.0)
      : a(aa), b(bb), c(cc), normal(nn), mat_ptr(mm), scale(s){

        e1 = b - a;
        e2 = c - a;

        normal = cross(e1, e2);
        normal = unit_vector(normal);

        d = dot(normal, a);
      }

    virtual bool hit(const ray& r, double tmin, double t_max, hit_record&) const override;
    virtual bool bounding_box(double t0, double t1, aabb& box) const override;

    vec3 a, b, c;
    vec3 e1, e2;
    vec3 normal;
    double area;
    double scale;
    double d;
    shared_ptr<material> mat_ptr;
};

bool triangle::hit(const ray& r, double tmin, double t_max, hit_record&) const{

  return true;
}

bool triangle::bounding_box(double t0, double t1, aabb& box) const{

  return true;
}

#endif /* TRIANGLE_H */
