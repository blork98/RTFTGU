#ifndef AMBIENT_LIGHT_H_
#define AMBIENT_LIGHT_H_

#include <Light.h>

namespace RTFTGU
{
	class AmbientLight : public Light
	{
		public:
			AmbientLight();
			virtual ~AmbientLight();

			void scale_radiance(const float b);
			void set_color(const float c);
			void set_color(const RGBColor& c);
			void set_color(const float r, const float g, const float b);

			virtual Vector3D get_direction(ShadeRec& s);
			virtual RGBColor L(ShadeRec& s);

		private:
			float		ls;
			RGBColor	color;
	};
}

#endif