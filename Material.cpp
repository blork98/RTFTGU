#include <Material.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------- default constructor

	Material::Material() 
	{}

	// ---------------------------------------------------------------- destructor

	Material::~Material()
	{}

	// ---------------------------------------------------------------- shade

	RGBColor
	Material::shade(ShadeRec& sr) 
	{
		return (black);
	}

	RGBColor
	Material::whitted_shade(ShadeRec& sr)
	{
		return black;
	}

	RGBColor
	Material::area_light_shade(ShadeRec& sr)
	{
		return black;
	}

	RGBColor
	Material::path_shade(ShadeRec& sr)
	{
		return black;
	}

	RGBColor
	Material::get_Le(ShadeRec& sr) const
	{
		return black;
	}

}