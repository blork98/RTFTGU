#include <Light.h>

#include <Constants.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------------- default constructor

	Light::Light(void)
		: shadow(false)
	{}

	// ---------------------------------------------------------------------- destructor

	Light::~Light() 
	{}

	// ---------------------------------------------------------------------- L
	// returns the radiance

	RGBColor
	Light::L(ShadeRec& s)
	{
		return (black);
	}

	bool
	Light::in_shadow(const Ray& ray, const ShadeRec& sr) const
	{
		return false;
	}

	bool
	Light::casts_shadow() const
	{
		return shadow;
	}

	void
	Light::enable_shadows(bool enable_shadows)
	{
		shadow = enable_shadows;
	}

	RGBColor
	Light::G(ShadeRec& sr)
	{
		return 1.0f;
	}

	float
	Light::pdf(ShadeRec& sr)
	{
		return 1.0f;
	}
}