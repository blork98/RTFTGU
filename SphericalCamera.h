#ifndef SPHERICAL_CAMERA_H_
#define SPHERICAL_CAMERA_H_

#include <Camera.h>
#include <Point2D.h>

namespace RTFTGU
{
	class SphericalCamera : public Camera
	{
		public:
			SphericalCamera();
			SphericalCamera(float view_field_vertical, float view_field_horizontal);
			~SphericalCamera();

			Vector3D ray_direction(const Point2D& p, const int hres,
				const int vres, const float s) const;
			void render_scene(Scene* w);

			void set_view_field_vertical(float psi_max_);
			void set_view_field_horizontal(float lambda_max);

		private:
			float psi_max;
			float lambda_max;
	};
}

#endif