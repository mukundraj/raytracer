#ifndef TRIANGLE_H
#define TRIANGLE_H

// #include "aarect.h"
#include "hittable.h"
#include <cmath>

class triangle: public hittable{
  public:

    triangle(){};

    triangle(vec3& aa, vec3&bb, vec3& cc, vec3& nn, shared_ptr<material> mm, double s=1.0)
      : a(aa), b(bb), c(cc), normal(nn), mat_ptr(mm), scale(s){

        e1 = b - a;
        e2 = c - a;

        normal = cross(e1, e2);
        normal = unit_vector(normal);

      }

    virtual bool hit(const ray& r, double t_min, double t_max, hit_record&) const override;
    virtual bool bounding_box(double t0, double t1, aabb& box) const override;

    vec3 a, b, c;
    vec3 e1, e2;
    vec3 normal;
    double scale;
    shared_ptr<material> mat_ptr;
};

// https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
// Möller-Trumbore algorithm
bool triangle::hit(const ray& r, double t_min, double t_max, hit_record& rec) const{

  const double eps = 1e-12;

  vec3 dir = r.direction();
  vec3 pvec = cross(dir, e2);

  const double det = dot(e1, pvec);


  if (fabs(det) < eps) return false;

  double invDet = 1 / det;

  vec3 tvec = r.origin() - a;
  double u = dot(tvec, pvec) * invDet;

  if (u<0 || u>1) return false;


  const vec3 qvec = cross(pvec, e1);
  double v = dot(dir, qvec) * invDet;
  if (v < 0 || u+v > 1) return false;


  double t = dot(e2, qvec) * invDet;

  if (t<t_min || t>t_max)
    return false;

  // interection is valid
  
  rec.u = (a.u() * (1.0 - u - v) + b.u() * u + c.u() * v);
  rec.v = (a.v() * (1.0 - u - v) + b.v() * u + c.v() * v);
  rec.t = t;
  rec.p = r.at(rec.t);
  rec.normal = normal;
  rec.mat_ptr = mat_ptr;
  return true;
}

bool triangle::bounding_box(double t0, double t1, aabb& box) const{
  float minX = fmin(fmin(a.x(), b.x()), c.x());
  float minY = fmin(fmin(a.y(), b.y()), c.y());
  float minZ = fmin(fmin(a.z(), b.z()), c.z());


  float maxX = fmax(fmax(a.x(), b.x()), c.x());
  float maxY = fmax(fmax(a.y(), b.y()), c.y());
  float maxZ = fmax(fmax(a.z(), b.z()), c.z());

  box = aabb((vec3(minX - 0.0001, minY - 0.0001, minZ - 0.0001)), (vec3(maxX + 0.0001, maxY + 0.0001, maxZ + 0.0001)));

  return true;
}

#endif /* TRIANGLE_H */
