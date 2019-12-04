#include <AmbientOccluder.h>
#include <ShadeRec.h>
#include <Scene.h>

namespace RTFTGU
{
	AmbientOccluder::AmbientOccluder()
		:u(0.0),
		v(0.0),
		w(0.0),
		ls(1.0),
		color(1.0),
		min_amount(0.0)
	{}

	AmbientOccluder::~AmbientOccluder(void)
	{}

	void
	AmbientOccluder::set_sampler(std::shared_ptr<Sampler> s_ptr )
	{
		sampler_ptr = s_ptr;
		sampler_ptr->map_samples_to_hemisphere(1);
	}

	Vector3D
	AmbientOccluder::get_direction(ShadeRec& s)
	{
		Point3D sp = sampler_ptr->sample_hemisphere();
		return (sp.x * u + sp.y * v + sp.z * w);
	}

	bool
	AmbientOccluder::in_shadow(const Ray& ray, const ShadeRec& sr) const
	{
		double 	t;
		int 	num_objects = sr.w.objects.size();

		for (int j = 0; j < num_objects; j++)
			if (sr.w.objects[j]->shadow_hit(ray, t))
				return (true);

		return (false);
	}

	RGBColor
	AmbientOccluder::L(ShadeRec& sr)
	{
		w = sr.normal;
		//jitter vector in case normal is vertical
		v = w ^ Vector3D(0.0072, 1.00, 0.0034);
		v.normalize();
		u = v ^ w;

		Ray shadow_ray;
		shadow_ray.o = sr.hit_point;
		shadow_ray.d = get_direction(sr);

		if (in_shadow(shadow_ray, sr))
			return (min_amount*ls*color);
		else
			return (ls*color);
	}

	void
	AmbientOccluder::scale_radiance(const float b)
	{
		ls = b;
	}

	void
	AmbientOccluder::set_color(const float c)
	{
		color.r = c; color.g = c; color.b = c;
	}

	void
	AmbientOccluder::set_color(const RGBColor& c)
	{
		color = c;
	}

	void
	AmbientOccluder::set_color(const float r, const float g, const float b)
	{
		color.r = r; color.g = g; color.b = b;
	}

	void
	AmbientOccluder::set_min_amount(float min_amount_)
	{
		min_amount = min_amount_;
	}

}
