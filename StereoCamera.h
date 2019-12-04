#ifndef STEREO_CAMERA_H_
#define STEREO_CAMERA_H_

#include <Camera.h>
#include <memory>

namespace RTFTGU
{

	enum ViewingType { parallel, transverse };

	class StereoCamera : public Camera
	{
		public:
			StereoCamera();
			~StereoCamera();

			void setup_cameras();
			void render_scene(Scene* w);

			void set_left_camera(std::shared_ptr<Camera> left);
			void set_right_camera(std::shared_ptr<Camera> right);
			void set_viewing(ViewingType viewing);
			void set_pixel_gap(int pix_gap);
			void set_beta(float beta);

		private:
			ViewingType viewing;
			int pixel_gap;
			float beta;
			std::shared_ptr<Camera> left_camera_ptr;
			std::shared_ptr<Camera> right_camera_ptr;
	};

}
#endif