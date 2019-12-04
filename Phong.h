#ifndef PHONG_H_
#define PHONG_H_

#include <Material.h>
#include <LambertianBRDF.h>
#include <GlossySpecularBRDF.h>

namespace RTFTGU
{
	class Phong : public Material
	{
		public:
			Phong();
			virtual ~Phong();

			RGBColor shade(ShadeRec& sr);
			RGBColor area_light_shade(ShadeRec& sr);

			//set lambertian data
			void set_ka(const float k);
			void set_kd(const float k);
			void set_cd(const RGBColor c);
			void set_cd(const float r, const float g, const float b);
			void set_cd(const float c);

			//set glossy specular data
			void set_ks(const float ks);
			void set_exp(const float exp);
			void set_cs(const RGBColor& c);
			void set_cs(const float r, const float g, const float b);
			void set_cs(const float c);
			//void set_sampler(std::shared_ptr<Sampler> sp, const float exp);   			// any type of sampling
			//void set_samples(const int num_samples, const float exp);

		protected:
			std::shared_ptr<Lambertian>		ambient_brdf;
			std::shared_ptr<Lambertian>		diffuse_brdf;
			std::shared_ptr<GlossySpecularBRDF>	specular_brdf;
	};

	class Blinn : public Phong
	{
		public:
			Blinn();
			~Blinn();

			RGBColor shade(ShadeRec& sr);
	};
}

#endif