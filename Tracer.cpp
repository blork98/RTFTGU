#include <Tracer.h>

#include <Constants.h>

namespace RTFTGU
{
	// -------------------------------------------------------------------- default constructor

	Tracer::Tracer(void)
		: scene_ptr(NULL)
	{}


	// -------------------------------------------------------------------- constructor

	Tracer::Tracer(Scene* scene)
		: scene_ptr(scene)
	{}

	// -------------------------------------------------------------------- destructor

	Tracer::~Tracer(void) 
	{}

	// -------------------------------------------------------------------- trace_ray

	RGBColor
		Tracer::trace_ray(const Ray& ray) const 
	{
		return (black);
	}


	// -------------------------------------------------------------------- trace_ray

	RGBColor
		Tracer::trace_ray(const Ray ray, const int depth) const 
	{
		return (black);
	}

	RGBColor
		Tracer::trace_ray(const Ray ray, float& tmin, const int depth) const
	{
		return (black);
	}
}