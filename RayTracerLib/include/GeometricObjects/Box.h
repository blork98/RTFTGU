#ifndef BOX_H_
#define BOX_H_

#include <GeometricObject.h>

namespace RTFTGU
{
	class Box : public GeometricObject
	{
		public:
			Box();
			Box(const double x0, const double x1,
				const double y0, const double y1,
				const double z0, const double z1);
			Box(const Point3D p0, const Point3D p1);
			~Box();

			bool hit(const Ray& ray, double& t, ShadeRec& s) const;
			bool shadow_hit(const Ray& ray, double& tmin) const;
			virtual Normal get_normal(const int face_hit) const;

		private:
			double x0, x1, y0, y1, z0, z1;

	};
}

#endif
