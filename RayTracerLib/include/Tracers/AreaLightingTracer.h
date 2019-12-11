#ifndef AREA_LIGHTING_TRACER_H_
#define AREA_LIGHTING_TRACER_H_

#include <Tracer.h>

namespace RTFTGU
{
	class AreaLightingTracer : public Tracer
	{
	public:

		AreaLightingTracer();
		AreaLightingTracer(Scene* _worldPtr);

		virtual ~AreaLightingTracer(void);

		virtual RGBColor trace_ray(const Ray ray, const int depth) const;

	};
}

#endif
