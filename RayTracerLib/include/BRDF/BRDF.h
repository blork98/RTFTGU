#ifndef BRDF_H_
#define BRDF_H_

#include <RGB.h>
#include <Vector3D.h>
#include <ShadeRec.h>
#include <Sampler.h>

#include <memory>

namespace RTFTGU
{
	class BRDF
	{
		public:
			BRDF();
			virtual ~BRDF();

			void set_sampler(std::shared_ptr<Sampler> sPtr);

			virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
			virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;
			virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
			virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

		protected:
			std::shared_ptr<Sampler> sampler_ptr;

	};
}

#endif
