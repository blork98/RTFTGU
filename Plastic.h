#ifndef PLASTIC_H_
#define PLASTIC_H_

#include <Material.h>
#include <BRDF.h>

namespace RTFTGU
{
	class Plastic : public Material
	{
		public:
			Plastic();
			virtual ~Plastic();

			RGBColor shade(ShadeRec& sr);

			void set_ambient_brdf(std::shared_ptr<BRDF> brdf);
			void set_diffuse_brdf(std::shared_ptr<BRDF> brdf);
			void set_specular_brdf(std::shared_ptr<BRDF> brdf);

		private:
			std::shared_ptr<BRDF>		ambient_brdf;
			std::shared_ptr<BRDF>		diffuse_brdf;
			std::shared_ptr<BRDF>		specular_brdf;
	};
}

#endif