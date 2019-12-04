#ifndef THINLENS_CAMERA_H_
#define THINLENS_CAMERA_H_

#include <Camera.h>
#include <Vector3D.h>
#include <Sampler.h>
#include <memory>

namespace RTFTGU
{
	class ThinLensCamera : public Camera
	{
		public:
			ThinLensCamera();
			~ThinLensCamera();

			void set_sampler(std::shared_ptr<Sampler> sp);
			Vector3D ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const;
			void render_scene(Scene* w);

		private:
			float lens_radius;
			float d, f;
			float zoom;
			std::shared_ptr<Sampler> sampler_ptr;
	};
}

#endif