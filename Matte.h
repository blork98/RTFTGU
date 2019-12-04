#ifndef MATTE_H_
#define MATTE_H_

#include <Material.h>
#include <LambertianBRDF.h>

namespace RTFTGU
{
	class Matte : public Material
	{
		public:
			Matte();
			~Matte();

			void set_ka(const float k);
			void set_kd(const float k);
			void set_cd(const RGBColor c);
			void set_cd(const float r, const float g, const float b);
			void set_cd(const float c);

			virtual RGBColor shade(ShadeRec& sr);
			virtual RGBColor area_light_shade(ShadeRec& sr);

		private:
			std::shared_ptr<Lambertian> ambient_brdf;
			std::shared_ptr<Lambertian> diffuse_brdf;
	};
}

#endif