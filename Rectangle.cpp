#include <Rectangle.h>

#include <Constants.h>

namespace RTFTGU
{
	// ----------------------------------------------------------------  default constructor

	Rectangle::Rectangle()
		: GeometricObject(),
		p0(-1, 0, -1),
		a(0, 0, 2), b(2, 0, 0),
		a_len_squared(4.0),
		b_len_squared(4.0),
		normal(0, 1, 0),
		area(4.0),
		inv_area(0.25)
	{}

	// ----------------------------------------------------------------  constructor
	// this constructs the normal

	Rectangle::Rectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b)
		: GeometricObject(),
		p0(_p0),
		a(_a),
		b(_b),
		a_len_squared(a.len_squared()),
		b_len_squared(b.len_squared()),
		area(a.length() * b.length()),
		inv_area(1.0 / area)
	{
		normal = a ^ b;
		normal.normalize();
	}

	// ----------------------------------------------------------------  constructor
	// this has the normal as an argument

	Rectangle::Rectangle(const Point3D& _p0, const Vector3D& _a, const Vector3D& _b, const Normal& n)
		: GeometricObject(),
		p0(_p0),
		a(_a),
		b(_b),
		a_len_squared(a.len_squared()),
		b_len_squared(b.len_squared()),
		area(a.length() * b.length()),
		inv_area(1.0 / area),
		normal(n),
		sampler_ptr(NULL)
	{
		normal.normalize();
	}

	// ---------------------------------------------------------------- destructor

	Rectangle::~Rectangle(void) 
	{}

	//------------------------------------------------------------------ hit 

	bool
	Rectangle::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {

		double t = (p0 - ray.o) * normal / (ray.d * normal);

		if (t <= kEpsilon)
			return (false);

		Point3D p = ray.o + t * ray.d;
		Vector3D d = p - p0;

		double ddota = d * a;

		if (ddota < 0.0 || ddota > a_len_squared)
			return (false);

		double ddotb = d * b;

		if (ddotb < 0.0 || ddotb > b_len_squared)
			return (false);

		tmin = t;
		sr.normal = normal;
		sr.local_hit_point = p;

		return (true);
	}

	// ---------------------------------------------------------------- setSampler

	void
	Rectangle::set_sampler(std::shared_ptr<Sampler> sampler) 
	{
		sampler_ptr = sampler;
	}

	// ---------------------------------------------------------------- sample
	// returns a sample point on the rectangle

	Point3D
	Rectangle::sample(void) 
	{
		Point2D sample_point = sampler_ptr->sample_unit_square();
		return (p0 + sample_point.x * a + sample_point.y * b);
	}

	//------------------------------------------------------------------ get_normal 

	Normal
	Rectangle::get_normal(const Point3D& p) 
	{
		return (normal);
	}


	// ---------------------------------------------------------------- pdf

	float
	Rectangle::pdf(const ShadeRec& sr) 
	{
		return (inv_area);
	}
}