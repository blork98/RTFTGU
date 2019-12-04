#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <ShadeRec.h>
#include <RGB.h>
#include <Scene.h>

namespace RTFTGU
{
	class Material
	{
		public:
			Material();
			virtual ~Material();

			virtual RGBColor shade(ShadeRec& sr);
			virtual RGBColor whitted_shade(ShadeRec& sr);
			virtual RGBColor area_light_shade(ShadeRec& sr);
			virtual RGBColor path_shade(ShadeRec& sr);
			virtual RGBColor get_Le(ShadeRec& sr) const;
	};
}

#endif