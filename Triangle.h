#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <GeometricObject.h>

namespace RTFTGU
{
	class Triangle : public GeometricObject
	{
		public:
			Triangle();
			Triangle(const Point3D& a, const Point3D& b, const Point3D& c);
			~Triangle();

			void compute_normal(void);
			virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
			virtual bool shadow_hit(const Ray& ray, double& tmin) const;

		private:
			Point3D	v0, v1, v2;
			Normal	normal;

	};
}

#endif