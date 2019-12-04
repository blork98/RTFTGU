#ifndef POINT_LIGHT_H_
#define POINT_LIGHT_H_

#include <Light.h>

namespace RTFTGU
{
	class PointLight : public Light
	{
		public:
			PointLight();
			virtual ~PointLight();

			void set_location(const Point3D& location);
			void scale_radiance(const float b);
			void set_color(const float c);
			void set_color(const RGBColor& c);
			void set_color(const float r, const float g, const float b);
			void enable_distance_attenuation(bool distAtt, unsigned int p);

			Vector3D get_direction(ShadeRec& s);
			RGBColor L(ShadeRec& s);
			bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

		private:
			float ls;
			RGBColor color;
			Point3D location;
			bool useDistAttenuation;
			unsigned int p;
	};
}

#endif