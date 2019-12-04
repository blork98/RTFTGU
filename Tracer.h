#ifndef TRACER_H_
#define TRACER_H_

#include <Constants.h>
#include <Ray.h>
#include <RGB.h>

#include <memory>

namespace RTFTGU
{
	class Scene;
	class Tracer
	{
		public:
			Tracer();
			Tracer( Scene* scene);
			virtual ~Tracer(void);

			virtual RGBColor trace_ray(const Ray& ray) const;
			virtual RGBColor trace_ray(const Ray ray, const int depth) const;
			virtual RGBColor trace_ray(const Ray ray, float& tmin, const int depth) const;

		protected:
			Scene* scene_ptr;
	};
}

#endif