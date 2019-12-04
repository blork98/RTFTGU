#ifndef GEOMETRIC_OBJECT_H_
#define GEOMETRIC_OBJECT_H_

#include <Ray.h>
#include <RGB.h>
#include <ShadeRec.h>
#include <memory>

namespace RTFTGU
{
	class GeometricObject 
	{

		public:

			GeometricObject(void);									// default constructor
			GeometricObject(const GeometricObject& object);			// copy constructor

			virtual ~GeometricObject(void);							// destructor

			virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const = 0;
			virtual bool shadow_hit(const Ray& ray, double& t) const;

			// the following three functions are only required for Chapter 3

			void set_color(const RGBColor& c);
			void set_color(const float r, const float g, const float b);
			void set_shadow(bool shadow_);

			RGBColor get_color(void);
			std::shared_ptr<Material> get_material() const;

			virtual void set_material(std::shared_ptr<Material> mPtr);							// needs to virtual so that it can be overriden in Compound
			virtual Point3D sample();
			virtual float pdf(const ShadeRec& sr);

			virtual Normal get_normal() const;
			virtual Normal get_normal(const Point3D& p);

			//virtual void set_bounding_box();
			//virtual BBox get_bounding_box();

		protected:

			RGBColor			color;				// only used for Bare Bones ray tracing
			mutable std::shared_ptr<Material>   material_ptr;
			bool shadow;
	};

	inline void GeometricObject::set_color(const RGBColor& c) 
	{
		color = c;
	}

	inline void GeometricObject::set_color(const float r, const float g, const float b) 
	{
		color.r = r;
		color.b = b;
		color.g = g;
	}

	inline RGBColor GeometricObject::get_color(void) 
	{
		return (color);
	}

}

#endif