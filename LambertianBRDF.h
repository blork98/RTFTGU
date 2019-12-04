#ifndef LAMBERTIAN_BRDF_H_
#define LAMBERTIAN_BRDF_H_

#include <BRDF.h>

namespace RTFTGU
{
	class Lambertian : public BRDF
	{
		public:
			Lambertian();
			virtual ~Lambertian();

			void set_ka(const float ka);
			void set_kd(const float kd);
			void set_cd(const RGBColor& c);
			void set_cd(const float r, const float g, const float b);
			void set_cd(const float c);

			virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
			virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
			virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

		private:
			float		kd;
			RGBColor 	cd;
	};
}

#endif