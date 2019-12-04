#include <DirectionalLight.h>

#include <Constants.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------------- default constructor
	
	DirectionalLight::DirectionalLight()
		: Light(),
		ls(1.0),
		color(1.0),
		dir(0, 1, 0)
	{}

	// ---------------------------------------------------------------------- destructor																			

	DirectionalLight::~DirectionalLight()
	{}

	// ---------------------------------------------------------------------- get_direction
	// as this function is virtual, it shouldn't be inlined 

	Vector3D
	DirectionalLight::get_direction(ShadeRec& sr) 
	{
		return (dir);
	}

	// ------------------------------------------------------------------------------  L

	RGBColor
	DirectionalLight::L(ShadeRec& s) 
	{
		return (ls * color);
	}

	// ------------------------------------------------------------------------------- scale_radiance

	void
	DirectionalLight::scale_radiance(const float b) 
	{
		ls = b;
	}

	// ------------------------------------------------------------------------------- set_color

	void
	DirectionalLight::set_color(const float c) 
	{
		color.r = c; color.g = c; color.b = c;
	}


	// ------------------------------------------------------------------------------- set_color

	void
	DirectionalLight::set_color(const RGBColor& c) 
	{
		color = c;
	}


	// ------------------------------------------------------------------------------- set_color

	void
	DirectionalLight::set_color(const float r, const float g, const float b) 
	{
		color.r = r; color.g = g; color.b = b;
	}


	// ---------------------------------------------------------------------- set_direction

	void
	DirectionalLight::set_direction(Vector3D d) 
	{
		dir = d;
		dir.normalize();
	}


	// ---------------------------------------------------------------------- set_direction 

	void
	DirectionalLight::set_direction(float dx, float dy, float dz) 
	{
		dir.x = dx; dir.y = dy; dir.z = dz;
		dir.normalize();
	}

	bool
	DirectionalLight::in_shadow(const Ray& ray, const ShadeRec& sr) const
	{
		int num_objects = sr.w.objects.size();
		double t = 0.0;

		for (int j = 0; j < num_objects; ++j)
			if (sr.w.objects[j]->shadow_hit(ray, t))
				return true;

		return false;
	}
}