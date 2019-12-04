#include <GeometricObject.h>

#include <Constants.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------------- default constructor

	GeometricObject::GeometricObject(void)
		: color(black),
		shadow(true)
	{}


	// ---------------------------------------------------------------------- copy constructor

	GeometricObject::GeometricObject(const GeometricObject& object)
		: color(object.color),
		shadow(object.shadow)
	{}

	GeometricObject::~GeometricObject(void)
	{}

	bool
	GeometricObject::shadow_hit(const Ray& ray, double& t) const
	{
		return false;
	}

	void
	GeometricObject::set_shadow(bool shadow_)
	{
		shadow = shadow_;
	}

	Normal
	GeometricObject::get_normal() const
	{
		return (Normal());
	}

	Normal
	GeometricObject::get_normal(const Point3D& p)
	{
		return (Normal());
	}
	
	Point3D
	GeometricObject::sample()
	{
		return (Point3D(0.0));
	}

	float
	GeometricObject::pdf(const ShadeRec& sr)
	{
		return (0.0);
	}

	std::shared_ptr<Material>
	GeometricObject::get_material(void) const
	{
		return (material_ptr);
	}

	void 
	GeometricObject::set_material(std::shared_ptr<Material> mPtr)
	{
		material_ptr = mPtr;
	}

}