#ifndef GLOSSY_SPECULAR_BRDF
#define GLOSSY_SPECULAR_BRDF

#include <BRDF.h>

namespace RTFTGU
{
	class GlossySpecularBRDF : public BRDF
	{
		public:
			GlossySpecularBRDF();
			~GlossySpecularBRDF();

			RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
			RGBColor f_blinn(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
			RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

			void set_ks(const float ks);
			void set_exp(const float exp);
			void set_cs(const RGBColor& c);
			void set_cs(const float r, const float g, const float b);
			void set_cs(const float c);
			//void set_sampler(std::shared_ptr<Sampler>	sampler, const float exp);   			// any type of sampling
			//void set_samples(const int num_samples, const float exp); 						// multi jittered sampling

		private:
			float		ks;
			RGBColor 	cs;							// specular color
			float		exp; 						// specular exponent
			//std::shared_ptr<Sampler>	sampler;    // for use in sample_f
	};
}

#endif