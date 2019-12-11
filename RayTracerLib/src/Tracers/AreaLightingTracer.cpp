#include <AreaLightingTracer.h>

#include <Scene.h>
#include <ShadeRec.h>
#include <Material.h>

namespace RTFTGU
{
	// -------------------------------------------------------------------- default constructor

	AreaLightingTracer::AreaLightingTracer()
		: Tracer()
	{}

	// -------------------------------------------------------------------- constructor

	AreaLightingTracer::AreaLightingTracer(Scene* _worldPtr)
		: Tracer(_worldPtr)
	{}

	// -------------------------------------------------------------------- destructor

	AreaLightingTracer::~AreaLightingTracer()
	{}

	// -------------------------------------------------------------------- trace_ray

	// The statement sr.ray = ray; is required for specular shading, computing the reflected and 
	// transmitted ray directions, and for rendering single sided emissive materials with area lights

	RGBColor
	AreaLightingTracer::trace_ray(const Ray ray, const int depth) const 
	{
		if (depth > scene_ptr->vp.max_depth)
			return (black);
		else 
		{
			ShadeRec sr(scene_ptr->hit_objects(ray));

			if (sr.hit_an_object) 
			{
				sr.depth = depth;
				sr.ray = ray;

				return (sr.material_ptr->area_light_shade(sr));
			}
			else
				return (scene_ptr->background_color);
		}
	}
}
