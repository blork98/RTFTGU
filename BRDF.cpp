#include <BRDF.h>

#include <Constants.h>

namespace RTFTGU
{
	BRDF::BRDF()
	{}

	BRDF::~BRDF()
	{}

	void 
	BRDF::set_sampler(std::shared_ptr<Sampler> sPtr)
	{
		sampler_ptr = sPtr;
		sampler_ptr->map_samples_to_hemisphere(1);
	}

	// ------------------------------------------------------------------------ f

	RGBColor
	BRDF::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const 
	{
		return (black);
	}


	// ------------------------------------------------------------------------ sample_f

	RGBColor
	BRDF::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const 
	{
		return (black);
	}


	// ------------------------------------------------------------------------ sample_f

	RGBColor
	BRDF::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const 
	{
		return (black);
	}


	// ------------------------------------------------------------------------ rho	

	RGBColor
	BRDF::rho(const ShadeRec& sr, const Vector3D& wo) const 
	{
		return (black);
	}

}