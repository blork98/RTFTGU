#ifndef DIRECTIONAL_LIGHT_H_
#define DIRECTIONAL_LIGHT_H_

#include <Light.h>
#include <Scene.h>			// you will need this later on for shadows
#include <ShadeRec.h>

namespace RTFTGU
{
	class DirectionalLight : public Light
	{
		public:
			DirectionalLight();
			virtual ~DirectionalLight();

			void scale_radiance(const float b);
			void set_color(const float c);
			void set_color(const RGBColor& c);
			void set_color(const float r, const float g, const float b);
			void set_direction(Vector3D d);
			void set_direction(float dx, float dy, float dz);

			virtual Vector3D get_direction(ShadeRec& sr);
			virtual RGBColor L(ShadeRec& sr);
			bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

		private:
			float		ls;
			RGBColor	color;
			Vector3D	dir;		// direction the light comes from
	};
}

#endif