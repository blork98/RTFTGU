#include <Matte.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------- default constructor

	Matte::Matte()
		: Material(),
		ambient_brdf(std::make_shared<Lambertian>()),
		diffuse_brdf(std::make_shared<Lambertian>())
	{}

	Matte::~Matte()
	{}

	// ---------------------------------------------------------------- set_ka
	// this sets Lambertian::kd
	// there is no Lambertian::ka data member because ambient reflection 
	// is diffuse reflection

	void
	Matte::set_ka(const float ka) 
	{
		ambient_brdf->set_kd(ka);
	}

	// ---------------------------------------------------------------- set_kd
	// this also sets Lambertian::kd, but for a different Lambertian object

	void
	Matte::set_kd(const float kd) 
	{
		diffuse_brdf->set_kd(kd);
	}

	// ---------------------------------------------------------------- set_cd

	void
	Matte::set_cd(const RGBColor c) 
	{
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
	}

	// ---------------------------------------------------------------- set_cd

	void
	Matte::set_cd(const float r, const float g, const float b) 
	{
		ambient_brdf->set_cd(r, g, b);
		diffuse_brdf->set_cd(r, g, b);
	}

	// ---------------------------------------------------------------- set_cd

	void
	Matte::set_cd(const float c) 
	{
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
	}

	RGBColor
	Matte::shade(ShadeRec& sr)
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
					L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi;


			}
		}

		return (L);
	}

	RGBColor 
	Matte::area_light_shade(ShadeRec& sr)
	{
		Vector3D 	wo = -sr.ray.d;
		RGBColor 	L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
		int 		num_lights = sr.w.lights.size();

		for (int j = 0; j < num_lights; j++) {
			Vector3D 	wi = sr.w.lights[j]->get_direction(sr);
			float 		ndotwi = sr.normal * wi;

			if (ndotwi > 0.0) 
			{
				bool in_shadow = false;

				if (sr.w.lights[j]->casts_shadow()) 
				{
					Ray shadow_ray(sr.hit_point, wi);
					in_shadow = sr.w.lights[j]->in_shadow(shadow_ray, sr);
				}

				if (!in_shadow)
				{
					//check here why area_light shade is wrong when in shadow
					RGBColor tempg = sr.w.lights[j]->G(sr);
					float temppdf = sr.w.lights[j]->pdf(sr);
					L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr)
						* sr.w.lights[j]->G(sr) * ndotwi / sr.w.lights[j]->pdf(sr);
				}
			}
		}

		return (L);
	}
}