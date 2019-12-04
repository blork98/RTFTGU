#ifndef CAMERA_H_
#define CAMERA_H_

#include <Point3D.h>
#include <Vector3D.h>

namespace RTFTGU
{

	class Scene;

	class Camera
	{
		public:
			Camera();
			virtual ~Camera();
			
			virtual void render_scene(Scene* scene) = 0;
			virtual void render_stereo(Scene* scene, float x, int offset);
			void compute_uvw(void);

			void set_eye(const Point3D& p);
			void set_eye(const float x, const float y, const float z);
			void set_lookat(const Point3D& p);
			void set_lookat(const float x, const float y, const float z);
			void set_up_vector(const Vector3D& u);
			void set_up_vector(const float x, const float y, const float z);
			void set_exposure_time(const float exposure);

			void set_roll(const float ra);
			void set_yaw(const float ra);
			void set_pitch(const float ra);

		protected:
			Point3D			eye;				// eye point
			Point3D			lookat; 			// lookat point
			float			ra;					// roll angle
			Vector3D		u, v, w;			// orthonormal basis vectors
			Vector3D		up;					// up vector
			float			exposure_time;

			void compute_T_roll( int n);
	};
}

#endif