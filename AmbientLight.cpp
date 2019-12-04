#include <AmbientLight.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------------- default constructor

	AmbientLight::AmbientLight(void)
		: Light(),
		ls(1.0),
		color(1.0)
	{}

	// ---------------------------------------------------------------------- destructor																			

	AmbientLight::~AmbientLight(void)
	{}

	// ---------------------------------------------------------------------- get_direction	

	Vector3D
	AmbientLight::get_direction(ShadeRec& s)
	{
		return (Vector3D(0.0));
	}

	// ---------------------------------------------------------------------- L

	RGBColor
	AmbientLight::L(ShadeRec& sr) 
	{
		return (ls * color);
	}

	// ------------------------------------------------------------------------------- set_color

	void
	AmbientLight::set_color(const float c) 
	{
		color.r = c; color.g = c; color.b = c;
	}


	// ------------------------------------------------------------------------------- set_color

	void
	AmbientLight::set_color(const RGBColor& c) 
	{
		color = c;
	}


	// ------------------------------------------------------------------------------- set_color

	void
	AmbientLight::set_color(const float r, const float g, const float b) 
	{
		color.r = r; color.g = g; color.b = b;
	}

	void
	AmbientLight::scale_radiance(const float b) 
	{
		ls = b;
	}
}