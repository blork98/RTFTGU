#ifndef EMISSIVE_H_
#define EMISSIVE_H_

#include <Material.h>

namespace RTFTGU
{
	class Emissive : public Material 
	{
		private:

			float		ls;		// radiance scaling factor						 
			RGBColor 	ce;		// color

		public:

			Emissive();
			Emissive(float ls_, RGBColor ce);
			~Emissive();

			void set_scale_radiance(const float _ls);
			void set_ce(const float r, const float g, const float b);
			void set_ce(const RGBColor& ce_);

			virtual RGBColor get_Le(ShadeRec& sr) const;

			virtual RGBColor shade(ShadeRec& sr);
			virtual RGBColor area_light_shade(ShadeRec& sr);
	};
}

#endif