#ifndef TORUS_H_
#define TORUS_H_

#include <GeometricObject.h>

namespace RTFTGU
{
	class Torus : public GeometricObject
	{
		public:
			Torus(void);
			Torus(const double _a, const double _b);
			virtual ~Torus(void);

			Normal compute_normal(const Point3D& p) const;

			bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
			bool shadow_hit(const Ray& ray, double& tmin) const;

		private:
			double 		a;	 	// swept radius 
			double		b;	 	// tube radius
	};
}

#endif