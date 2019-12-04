#ifndef LIGHT_H_
#define LIGHT_H_

#include <Vector3D.h>
#include <RGB.h>
#include <Ray.h>

namespace RTFTGU
{
	class ShadeRec;

	class Light
	{
		public:
			Light();
			virtual ~Light();

			bool casts_shadow() const;
			void enable_shadows(bool enable_shadows);

			virtual Vector3D get_direction(ShadeRec& sr) = 0;
			virtual RGBColor L(ShadeRec& sr);
			virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;
			virtual RGBColor G(ShadeRec& sr);
			virtual float pdf(ShadeRec& sr);

		private:
			bool shadow;
	};
}

#endif