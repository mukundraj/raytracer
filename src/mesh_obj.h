#ifndef MESH_OBJ_H
#define MESH_OBJ_H




#include "aarect.h"
#include "hittable_list.h"
#include "../external/OBJ_Loader.h"
#include <string>

class mesh_obj: public hittable {
  public:
    mesh_obj(){}
    // mesh_obj(shared_ptr<hittable_list> trianges, shared_ptr<material> ptr);
    // std::vector<shared_ptr<hittable>>   structure for storing triangles in intermediate step

    mesh_obj(std::string path_to_obj, float scale=1.0);

    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

    virtual bool bounding_box(double time0, double time1, aabb& output_box) const override{
      output_box = aabb(box_min, box_max);
      return true;
    }
  public:
    point3 box_min;
    point3 box_max;
    hittable_list triangles;

};

#endif /* MESH_OBJ_H */
