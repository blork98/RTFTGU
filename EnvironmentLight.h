#ifndef ENVIRONMENT_LIGHT_H_
#define ENVIRONMENT_LIGHT_H_

#include <Light.h>
#include <Material.h>
#include <Sampler.h>

#include <memory>

namespace RTFTGU
{
	class EnvironmentLight : public Light
	{
		public:
			EnvironmentLight();
			~EnvironmentLight();

			void set_material(std::shared_ptr<Material> material_ptr);
			void set_sampler(std::shared_ptr<Sampler> sampler_ptr);
			bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

			Vector3D get_direction(ShadeRec& sr);
			RGBColor L(ShadeRec& sr);
			float pdf(ShadeRec& sr);

		private:
			std::shared_ptr<Material> material_ptr;
			std::shared_ptr<Sampler> sampler_ptr;
			Vector3D u, v, w;
			Vector3D wi;
	};
}

#endif