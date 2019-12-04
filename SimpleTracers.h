#ifndef SIMPLE_TRACERS_H_
#define SIMPLE_TRACERS_H_

#include <Tracer.h>

namespace RTFTGU
{

	class SingleSphere : public Tracer 
	{
		public:

			SingleSphere();
			SingleSphere(Scene* scenePtr);
			virtual ~SingleSphere();

			virtual RGBColor trace_ray(const Ray& ray) const;
	};

	class MultipleObjectsTracer : public Tracer
	{
		public:
			MultipleObjectsTracer();
			MultipleObjectsTracer(Scene* _world_ptr);

			virtual ~MultipleObjectsTracer();

			virtual RGBColor trace_ray(const Ray& ray) const;
			virtual RGBColor trace_ray(const Ray ray, const int depth) const;
	};
}

#endif