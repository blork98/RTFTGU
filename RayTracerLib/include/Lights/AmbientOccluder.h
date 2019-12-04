#ifndef AMBIENT_OCCLUDER_H_
#define AMBIENT_OCCLUDER_H_

#include <Light.h>
#include <Sampler.h>

#include <memory>

namespace RTFTGU
{
	class AmbientOccluder : public Light
	{
		public:
			AmbientOccluder(void);
			virtual ~AmbientOccluder(void);

			void set_sampler(std::shared_ptr<Sampler> s_ptr);

			void scale_radiance(const float b);
			void set_color(const float c);
			void set_color(const RGBColor& c);
			void set_color(const float r, const float g, const float b);
			void set_min_amount(float min_amount_);

			Vector3D get_direction(ShadeRec& s);
			RGBColor L(ShadeRec& s);
			bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

		private:
			Vector3D u, v, w;
			std::shared_ptr<Sampler> sampler_ptr;
			float		ls;
			RGBColor	color;
			float 		min_amount;
	};
}

#endif
