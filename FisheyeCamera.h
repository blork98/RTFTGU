#ifndef FISHEYE_CAMERA_H_
#define FISHEYE_CAMERA_H_

#include <Camera.h>
#include <Vector3D.h>
#include <Point2D.h>

namespace RTFTGU
{
	class FishEyeCamera : public Camera
	{
		public:
			FishEyeCamera();
			FishEyeCamera(float view_field);
			~FishEyeCamera();

			Vector3D ray_direction(const Point2D& p, const int hres,
				const int vres, const float s, float& r) const;
			void render_scene(Scene* w);
			void set_view_field(float psi_max_);
			void set_view_direction( const Vector3D& dr, double d);

		private:
			float psi_max;
	};
}

#endif