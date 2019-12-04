#include <RayCast.h>

#include <Material.h>
#include <Scene.h>

namespace RTFTGU
{
	// -------------------------------------------------------------------- default constructor

	RayCast::RayCast(void)
		: Tracer()
	{}


	// -------------------------------------------------------------------- constructor

	RayCast::RayCast(Scene* scene_ptr)
		: Tracer(scene_ptr)
	{}

	// -------------------------------------------------------------------- destructor

	RayCast::~RayCast(void) 
	{}

	// -------------------------------------------------------------------- trace_ray

	RGBColor
	RayCast::trace_ray(const Ray& ray) const
	{
		ShadeRec sr(scene_ptr->hit_objects(ray));

		if (sr.hit_an_object) 
		{
			sr.ray = ray;			// used for specular shading
			return (sr.material_ptr->shade(sr));
		}
		else
			return (scene_ptr->background_color);
	}

	// -------------------------------------------------------------------- trace_ray
	// this ignores the depth argument

	RGBColor
	RayCast::trace_ray(const Ray ray, const int depth) const
	{
		ShadeRec sr(scene_ptr->hit_objects(ray));

		if (sr.hit_an_object) 
		{
			sr.ray = ray;			// used for specular shading
			return (sr.material_ptr->shade(sr));
		}
		else
			return (scene_ptr->background_color);
	}
}