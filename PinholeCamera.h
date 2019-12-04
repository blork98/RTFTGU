#ifndef PINHOLE_CAMERA_H_
#define PINHOLE_CAMERA_H_

#include <Camera.h>
#include <Point2D.h>
#include <Scene.h>


namespace RTFTGU
{
	class PinholeCamera : public Camera
	{
		public:
			PinholeCamera();
			virtual ~PinholeCamera();

			void set_view_distance(const float vpd);
			void set_zoom(const float zoom_factor);

			Vector3D get_direction(const Point2D& p) const;
			virtual void render_scene(Scene* w);
			void render_stereo(Scene* w, float x, int offset);

		private:
			float d, zoom;
	};
}

#endif