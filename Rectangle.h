#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <GeometricObject.h>
#include <Sampler.h>

namespace RTFTGU
{
	class Rectangle : public GeometricObject
	{
		public:
			Rectangle();
			Rectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b);
			Rectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b, const Normal& n);
			virtual ~Rectangle();

			//BBox get_bounding_box(void);
			virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;

			// the following functions are used when the rectangle is a light source

			virtual void set_sampler(std::shared_ptr<Sampler> sampler);
			virtual Point3D sample();
			virtual Normal get_normal(const Point3D& p);
			virtual float pdf(const ShadeRec& sr);

		private:

			Point3D 		p0;   			// corner vertex 
			Vector3D		a;				// side
			Vector3D		b;				// side
			double			a_len_squared;	// square of the length of side a
			double			b_len_squared;	// square of the length of side b
			Normal			normal;

			float			area;			// for rectangular lights
			float			inv_area;		// for rectangular lights
			std::shared_ptr<Sampler>		sampler_ptr;	// for rectangular lights 	
	};
}



#endif