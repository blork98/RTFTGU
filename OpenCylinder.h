#ifndef OPEN_CYLINDER_H_
#define OPEN_CYLINDER_H_

#include <GeometricObject.h>

namespace RTFTGU
{
	class OpenCylinder : public GeometricObject
	{
		public:
			OpenCylinder();
			OpenCylinder(const double bottom, const double top, const double radius);
			~OpenCylinder();

			bool hit(const Ray& ray, double& t, ShadeRec& s) const;
			bool shadow_hit(const Ray& ray, double& tmin) const;

		private:
			double		y0;				// bottom y value
			double		y1;				// top y value
			double		radius;			// radius
			double		inv_radius;  	// one over the radius	
	};
}

#endif