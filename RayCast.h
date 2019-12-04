#ifndef RAY_CAST_H_
#define RAY_CAST_H_

#include <Tracer.h>

namespace RTFTGU
{
	class RayCast : public Tracer
	{
		public:
			RayCast();
			RayCast(Scene* _scenePtr);
			virtual ~RayCast();

			RGBColor trace_ray(const Ray ray, const int depth) const;
			RGBColor trace_ray(const Ray& ray) const;
	};
}

#endif

