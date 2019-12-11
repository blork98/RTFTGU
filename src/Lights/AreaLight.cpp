#include <AreaLight.h>

namespace RTFTGU
{
	AreaLight::AreaLight()
		: Light()
	{}

	AreaLight::~AreaLight(void) 
	{}

	void
	AreaLight::set_object(std::shared_ptr<GeometricObject> obj_ptr)
	{
		object_ptr = obj_ptr;
		material_ptr = object_ptr->get_material();
	}

	Vector3D
	AreaLight::get_direction(ShadeRec& sr)
	{
		sample_point = object_ptr->sample();    // used in the G function
		light_normal = object_ptr->get_normal(sample_point);
		wi = sample_point - sr.hit_point;  		// used in the G function
		wi.normalize();

		return (wi);
	}

	bool
	AreaLight::in_shadow(const Ray& ray, const ShadeRec& sr) const
	{
		double t;
		int num_objects = sr.w.objects.size();
		float ts = (sample_point - ray.o) * ray.d;

		for (int j = 0; j < num_objects; j++)
			if (sr.w.objects[j]->shadow_hit(ray, t) && t < ts)
				return (true);

		return (false);
	}

	RGBColor
	AreaLight::L(ShadeRec& sr)
	{
		float ndotd = -light_normal * wi;

		if (ndotd > 0.0)
			return (material_ptr->get_Le(sr));
		else
			return (black);
	}

	RGBColor
	AreaLight::G(ShadeRec& sr)
	{
		float ndotd = -light_normal * wi;
		float d2 = sample_point.d_squared(sr.hit_point);

		return (ndotd / d2);
	}

	float
	AreaLight::pdf(ShadeRec& sr)
	{
		return (object_ptr->pdf(sr));
	}
}
