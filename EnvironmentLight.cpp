#include <EnvironmentLight.h>

namespace RTFTGU
{
	EnvironmentLight::EnvironmentLight()
		:Light()
	{}

	EnvironmentLight::~EnvironmentLight()
	{}

	Vector3D
	EnvironmentLight::get_direction(ShadeRec& sr)
	{
		w = sr.normal;
		v = Vector3D(0.0034, 1, 0.0071) ^ w;
		v.normalize();
		u = v ^ w;
		Point3D sp = sampler_ptr->sample_hemisphere();
		wi = sp.x * u + sp.y * v + sp.z * w;

		return (wi);
	}

	RGBColor
	EnvironmentLight::L(ShadeRec& sr) 
	{
		return (material_ptr->get_Le(sr));
	}

	// The following function is not in the book.
	// It uses Equation 18.6

	float
	EnvironmentLight::pdf(ShadeRec& sr) 
	{
		return (sr.normal * wi * invPI);
	}

	void 
	EnvironmentLight::set_sampler(std::shared_ptr<Sampler> sampler)
	{
		sampler_ptr = sampler;
		sampler_ptr->map_samples_to_hemisphere(1);
	}

	bool
	EnvironmentLight::in_shadow(const Ray& ray, const ShadeRec& sr) const
	{
		double 	t;
		int 	num_objects = sr.w.objects.size();

		for (int j = 0; j < num_objects; j++)
			if (sr.w.objects[j]->shadow_hit(ray, t))
				return (true);

		return (false);
	}

	void 
	EnvironmentLight::set_material(std::shared_ptr<Material> material)
	{
		material_ptr = material;
	}
}