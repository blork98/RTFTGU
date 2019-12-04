#include <LambertianBRDF.h>

#include <Constants.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------------- default constructor

	Lambertian::Lambertian(void)
		: BRDF(),
		kd(0.0),
		cd(0.0)
	{}

	// ---------------------------------------------------------------------- destructor

	Lambertian::~Lambertian(void) 
	{}

	// ---------------------------------------------------------------------- f
	// there is no sampling here

	RGBColor
	Lambertian::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const 
	{
		return (kd * cd * invPI);
	}

	// ---------------------------------------------------------------------- sample_f

	// this generates a direction by sampling the hemisphere with a cosine distribution
	// this is called in path_shade for any material with a diffuse shading component
	// the samples have to be stored with a cosine distribution

	RGBColor
	Lambertian::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const 
	{

		Vector3D w = sr.normal;
		Vector3D v = Vector3D(0.0034, 1, 0.0071) ^ w;
		v.normalize();
		Vector3D u = v ^ w;

		Point3D sp = sampler_ptr->sample_hemisphere();
		wi = sp.x * u + sp.y * v + sp.z * w;
		wi.normalize();

		pdf = sr.normal * wi * invPI;

		return (kd * cd * invPI);
	}

	// ---------------------------------------------------------------------- rho

	RGBColor
	Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const 
	{
		return (kd * cd);
	}

	//////////////////////

	void
	Lambertian::set_ka(const float k) 
	{
		kd = k;
	}

	void
	Lambertian::set_kd(const float k) 
	{
		kd = k;
	}

	// -------------------------------------------------------------- set_cd

	void
	Lambertian::set_cd(const RGBColor& c) 
	{
		cd = c;
	}


	// ---------------------------------------------------------------- set_cd
	void
	Lambertian::set_cd(const float r, const float g, const float b) 
	{
		cd.r = r; cd.g = g; cd.b = b;
	}


	// ---------------------------------------------------------------- set_cd

	void
	Lambertian::set_cd(const float c) 
	{
		cd.r = c; cd.g = c; cd.b = c;
	}
}