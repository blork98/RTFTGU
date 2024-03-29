#include <Plane.h>

#include <Constants.h>

namespace RTFTGU
{
	// ----------------------------------------------------------------------  default constructor

	Plane::Plane(void)
		: GeometricObject(),
		a(0.0),
		n(0, 1, 0)
	{}


	// ----------------------------------------------------------------------  constructor

	Plane::Plane(const Point3D& point, const Normal& normal)
		: GeometricObject(),
		a(point),
		n(normal)
	{
		n.normalize();
	}


	// ---------------------------------------------------------------- copy constructor

	Plane::Plane(const Plane& plane)
		: GeometricObject(plane),
		a(plane.a),
		n(plane.n)
	{}

	// ---------------------------------------------------------------- destructor

	Plane::~Plane(void)
	{}

	bool
	Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
	{
		double t = (a - ray.o) * n / (ray.d * n);

		if (t > kEpsilon) {
			tmin = t;
			sr.normal = n;
			sr.local_hit_point = ray.o + t * ray.d;

			return (true);
		}

		return(false);
	}

	bool
	Plane::shadow_hit(const Ray& ray, double& tmin) const
	{
		if (!shadow)
			return false;

		double t = (a - ray.o) * n / (ray.d * n);

		if (t > kEpsilon)
		{
			tmin = t;
			return true;
		}
		else
			return false;

	}

}