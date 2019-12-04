#include <PointLight.h>

#include <ShadeRec.h>
#include <MathUtils.h>
#include <Scene.h>

#include <cmath>

namespace RTFTGU
{
	PointLight::PointLight(void)
		:Light(),
		ls(1.0),
		color(1.0),
		location(0.0),
		useDistAttenuation(false),
		p(0)
	{}

	PointLight::~PointLight(void)
	{}

	void
	PointLight::set_location(const Point3D& location_)
	{
		location = location_;
	}

	void
	PointLight::set_color(const float c) 
	{
		color.r = c; color.g = c; color.b = c;
	}

	void
	PointLight::set_color(const RGBColor& c) 
	{
		color = c;
	}

	void
	PointLight::set_color(const float r, const float g, const float b) 
	{
		color.r = r; color.g = g; color.b = b;
	}

	void
	PointLight::enable_distance_attenuation(bool distAtt, unsigned int p_)
	{
		useDistAttenuation = distAtt;
		p = p_;
	}

	void
	PointLight::scale_radiance(const float b) 
	{
		ls = b;
	}

	Vector3D
	PointLight::get_direction(ShadeRec& s)
	{
		return (location - s.local_hit_point).hat();
	}

	RGBColor
	PointLight::L(ShadeRec& sr) 
	{
		double d = 1.0;

		if (useDistAttenuation == true)
		{
			d = location.distance(sr.local_hit_point);
			d = std::pow(d, p);
		}

		return (ls * color) / d;
	}

	bool
	PointLight::in_shadow(const Ray& ray, const ShadeRec& sr) const
	{
		double t = 0.0;
		double d = location.distance(ray.o);
		int num_objects = sr.w.objects.size();

		for (int j = 0; j < num_objects; ++j)
			if (sr.w.objects[j]->shadow_hit(ray, t) && t < d)
				return true;

		return false;
	}
}