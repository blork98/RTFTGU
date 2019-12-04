#include <Sphere.h>

#include <Constants.h>
#include <math.h>
#include <ShadeRec.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------- default constructor

	Sphere::Sphere(void)
		: GeometricObject(),
		center(0.0),
		radius(1.0)
	{}


	// ---------------------------------------------------------------- constructor

	Sphere::Sphere(Point3D c, double r)
		: GeometricObject(),
		center(c),
		radius(r)
	{}

	// ---------------------------------------------------------------- copy constructor

	Sphere::Sphere(const Sphere& sphere)
		: GeometricObject(sphere),
		center(sphere.center),
		radius(sphere.radius)
	{}

	// ---------------------------------------------------------------- destructor

	Sphere::~Sphere(void) {}

	void
	Sphere::set_center(const Point3D& c) 
	{
		center = c;
	}

	void
	Sphere::set_center(const double x, const double y, const double z) 
	{
		center.x = x;
		center.y = y;
		center.z = z;
	}

	void
	Sphere::set_radius(const double r) 
	{
		radius = r;
	}

	//---------------------------------------------------------------- hit

	bool
	Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const 
	{
		double 		t;
		Vector3D	temp = ray.o - center;
		double 		a = ray.d * ray.d;
		double 		b = 2.0 * temp * ray.d;
		double 		c = temp * temp - radius * radius;
		double 		disc = b * b - 4.0 * a * c;

		if (disc < 0.0)
			return(false);
		else {
			double e = sqrt(disc);
			double denom = 2.0 * a;
			t = (-b - e) / denom;    // smaller root

			if (t > kEpsilon) {
				tmin = t;
				sr.normal = (temp + t * ray.d) / radius;
				sr.local_hit_point = ray.o + t * ray.d;
				return (true);
			}

			t = (-b + e) / denom;    // larger root

			if (t > kEpsilon) {
				tmin = t;
				sr.normal = (temp + t * ray.d) / radius;
				sr.local_hit_point = ray.o + t * ray.d;
				return (true);
			}
		}

		return (false);
	}

	bool
	Sphere::shadow_hit(const Ray& ray, double& tmin) const
	{
		if (!shadow)
			return false;

		double 		t;
		Vector3D	temp = ray.o - center;
		double 		a = ray.d * ray.d;
		double 		b = 2.0 * temp * ray.d;
		double 		c = temp * temp - radius * radius;
		double 		disc = b * b - 4.0 * a * c;

		if (disc < 0.0)
			return(false);
		else {
			double e = sqrt(disc);
			double denom = 2.0 * a;
			t = (-b - e) / denom;    // smaller root

			if (t > kEpsilon) {
				tmin = t;
				return (true);
			}

			t = (-b + e) / denom;    // larger root

			if (t > kEpsilon) {
				tmin = t;
				return (true);
			}
		}

		return (false);
	}
}