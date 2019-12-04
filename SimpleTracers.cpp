#include <SimpleTracers.h>

#include <Constants.h>
#include <ShadeRec.h>
#include <Scene.h>

namespace RTFTGU
{
	// -------------------------------------------------------------------- default constructor

	SingleSphere::SingleSphere()
		: Tracer()
	{}


	// -------------------------------------------------------------------- constructor

	SingleSphere::SingleSphere(Scene* _scenePtr)
		: Tracer(_scenePtr)
	{}

	// -------------------------------------------------------------------- destructor

	SingleSphere::~SingleSphere(void) 
	{}

	// -------------------------------------------------------------------- trace_ray

	RGBColor
	SingleSphere::trace_ray(const Ray& ray) const 
	{
		ShadeRec	sr(*scene_ptr); 	// not used
		double    	t;  				// not used

		if (scene_ptr->sphere.hit(ray, t, sr))
			return (red);
		else
			return (black);
	}

	// -------------------------------------------------------------------- default constructor

	MultipleObjectsTracer::MultipleObjectsTracer(void)
		: Tracer()
	{}


	// -------------------------------------------------------------------- constructor

	MultipleObjectsTracer::MultipleObjectsTracer(Scene* _scenePtr)
		: Tracer(_scenePtr)
	{}

	// -------------------------------------------------------------------- destructor

	MultipleObjectsTracer::~MultipleObjectsTracer(void)
	{}

	// -------------------------------------------------------------------- trace_ray

	RGBColor
	MultipleObjectsTracer::trace_ray(const Ray& ray) const 
	{
		ShadeRec sr(scene_ptr->hit_bare_bones_objects(ray)); // sr is copy constructed

		if (sr.hit_an_object)
			return (sr.color);
		else
			return (scene_ptr->background_color);
	}

	RGBColor
	MultipleObjectsTracer::trace_ray(const Ray ray, const int depth) const
	{
		ShadeRec sr(scene_ptr->hit_bare_bones_objects(ray)); // sr is copy constructed

		if (sr.hit_an_object)
			return (sr.color);
		else
			return (scene_ptr->background_color);
	}

}