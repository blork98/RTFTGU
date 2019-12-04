#include <Emissive.h>

namespace RTFTGU
{
	Emissive::Emissive()
		:ls(0.0), ce(0.0, 0.0, 0.0)
	{}

	Emissive::Emissive(float ls_, RGBColor ce_)
		: ls(ls_), ce(ce_)
	{}

	Emissive::~Emissive()
	{}

	void
	Emissive::set_scale_radiance(const float _ls)
	{
		ls = _ls;
	}

	void
	Emissive::set_ce(const float r, const float g, const float b)
	{
		ce.r = r;
		ce.g = g;
		ce.b = b;
	}

	void 
	Emissive::set_ce(const RGBColor& ce_)
	{
		ce = ce_;
	}

	RGBColor
	Emissive::area_light_shade(ShadeRec& sr)
	{
		if (-sr.normal * sr.ray.d > 0.0)
			return (ls * ce);
		else
			return (black);
	}

	RGBColor
	Emissive::shade(ShadeRec& sr)
	{
		if (-sr.normal * sr.ray.d > 0.0)
			return (ls * ce);
		else
			return (black);
	}

	RGBColor
	Emissive::get_Le(ShadeRec& sr) const
	{
		return (ls * ce);
	}
}