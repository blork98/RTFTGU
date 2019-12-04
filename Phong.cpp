#include <Phong.h>

namespace RTFTGU
{
	Phong::Phong(void)
		:Material(),
		ambient_brdf(std::make_shared<Lambertian>()),
		diffuse_brdf(std::make_shared<Lambertian>()),
		specular_brdf(std::make_shared<GlossySpecularBRDF>())
	{}

	Phong::~Phong(void)
	{}

	// Glossy Specular
	void
	Phong::set_ks(const float ks)
	{
		specular_brdf->set_ks(ks);
	}

	void
		Phong::set_exp(const float exp)
	{
		specular_brdf->set_exp(exp);
	}

	void
	Phong::set_cs(const RGBColor& c)
	{
		specular_brdf->set_cs(c);
	}

	void
	Phong::set_cs(const float r, const float g, const float b)
	{
		specular_brdf->set_cs(r, g, b);
	}

	void
	Phong::set_cs(const float c)
	{
		specular_brdf->set_cs(c);
	}

	//void
	//Phong::set_sampler(Sampler* sp, const float exp)
	//{
	//	specular_brdf->set_sampler(sp, exp);
	//}

	//void
	//Phong::set_samples(const int num_samples, const float exp)
	//{
	//	specular_brdf->set_samples(num_samples, exp);
	//}

	// ---------------------------------------------------------------- set_ka
	// this sets Lambertian::kd
	// there is no Lambertian::ka data member because ambient reflection 
	// is diffuse reflection

	void
	Phong::set_ka(const float ka)
	{
		ambient_brdf->set_kd(ka);
	}

	// ---------------------------------------------------------------- set_kd
	// this also sets Lambertian::kd, but for a different Lambertian object

	void
	Phong::set_kd(const float kd)
	{
		diffuse_brdf->set_kd(kd);
	}

	// ---------------------------------------------------------------- set_cd

	void
	Phong::set_cd(const RGBColor c)
	{
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
	}

	// ---------------------------------------------------------------- set_cd

	void
	Phong::set_cd(const float r, const float g, const float b)
	{
		ambient_brdf->set_cd(r, g, b);
		diffuse_brdf->set_cd(r, g, b);
	}

	// ---------------------------------------------------------------- set_cd

	void
	Phong::set_cd(const float c)
	{
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
	}

	RGBColor
	Phong::shade(ShadeRec& sr)
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

	RGBColor 
	Phong::area_light_shade(ShadeRec& sr)
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
					sr.w.lights[j]->L(sr)* sr.w.lights[j]->G(sr) * ndotwi/ sr.w.lights[j]->pdf(sr);

			}
		}

		return (L);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	Blinn::Blinn(void)
		: Phong()
	{}

	Blinn::~Blinn()
	{}

	RGBColor 
	Blinn::shade(ShadeRec& sr)
	{
		Vector3D 	wo = -sr.ray.d;
		RGBColor 	L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
		int 		num_lights = sr.w.lights.size();

		for (int j = 0; j < num_lights; j++)
		{
			Vector3D wi = sr.w.lights[j]->get_direction(sr);
			float ndotwi = sr.normal * wi;

			if (ndotwi > 0.0)
				L += (diffuse_brdf->f(sr, wo, wi) + specular_brdf->f_blinn(sr, wo, wi)) *
				sr.w.lights[j]->L(sr) * ndotwi;
		}

		return L;
	}

}