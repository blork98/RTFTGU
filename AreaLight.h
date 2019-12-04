#ifndef AREA_LIGHT_H_
#define AREA_LIGHT_H_

#include<Light.h>
#include <Material.h>
#include <GeometricObject.h>

namespace RTFTGU
{
	class AreaLight : public Light
	{
		public:
			AreaLight();
			virtual ~AreaLight();

			void set_object(std::shared_ptr<GeometricObject> obj_ptr);
			virtual Vector3D get_direction(ShadeRec& s);
			virtual RGBColor L(ShadeRec& sr);
			virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;
			virtual RGBColor G(ShadeRec& sr);
			virtual float pdf(ShadeRec& sr);

		private:
			std::shared_ptr<GeometricObject>	object_ptr;
			std::shared_ptr<Material> 			material_ptr;	 // will be an emissive material
			Point3D				sample_point;
			Normal				light_normal;    // assigned in get_direction - which therefore can't be const for any light
			Vector3D			wi;			     // unit direction from hit point being shaded to sample point on light surface	
	};
}

#endif