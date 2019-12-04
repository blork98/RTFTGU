#include <Plastic.h>

namespace RTFTGU
{
	Plastic::Plastic(void)
		: Material(),
		ambient_brdf(nullptr),
		diffuse_brdf(nullptr),
		specular_brdf(nullptr)
	{}

	Plastic::~Plastic(void)
	{}

	void
	Plastic::set_ambient_brdf(std::shared_ptr<BRDF> brdf)
	{
		ambient_brdf = brdf;
	}

	void
	Plastic::set_diffuse_brdf(std::shared_ptr<BRDF> brdf)
	{
		diffuse_brdf = brdf;
	}

	void
	Plastic::set_specular_brdf(std::shared_ptr<BRDF> brdf)
	{
		specular_brdf = brdf;
	}

	RGBColor
	Plastic::shade(ShadeRec& sr)
	{
		Vector3D 	wo = -sr.ray.d;
		RGBColor 	L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
		int 		num_lights = sr.w.lights.size();

		for (int j = 0; j < num_lights; j++)
		{
			Vector3D wi = sr.w.lights[j]->get_direction(sr);
			float ndotwi = sr.normal * wi;

			if (ndotwi > 0.0)
			{
				bool in_shadow = false;

				if (sr.w.lights[j]->casts_shadow())
				{
					Ray shadowRay(sr.hit_point, wi);
					in_shadow = sr.w.lights[j]->in_shadow(shadowRay, sr);
				}

				if (!in_shadow)
					L += (diffuse_brdf->f(sr, wo, wi) + specular_brdf->f(sr, wo, wi)) *
					sr.w.lights[j]->L(sr) * ndotwi;
			}
		}

		return (L);
	}
}