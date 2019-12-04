#include <Camera.h>

#include <Matrix.h>
#define _USE_MATH_DEFINES
#include <cmath>

namespace RTFTGU
{
	Camera::Camera()
		:eye(0, 0, 500),
		lookat(0),
		ra(0),
		up(0, 1, 0),
		u(1, 0, 0),
		v(0, 1, 0),
		w(0, 0, 1),
		exposure_time(1.0)
	{}

	Camera::~Camera()
	{}

	void 
	Camera::compute_uvw(void)
	{
		w = eye - lookat;
		w.normalize();
		u = up ^ w;
		u.normalize();
		v = w ^ u;

		// take care of the singularity by hardwiring in specific camera orientations

		if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y)
		{ // camera looking vertically down
			u = Vector3D(0, 0, 1);
			v = Vector3D(1, 0, 0);
			w = Vector3D(0, 1, 0);
		}

		if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y)
		{ // camera looking vertically up
			u = Vector3D(1, 0, 0);
			v = Vector3D(0, 0, 1);
			w = Vector3D(0, -1, 0);
		}
	}

	// ----------------------------------------------------------------- set_eye

	void
	Camera::set_eye(const Point3D& p) 
	{
		eye = p;
	}

	// ----------------------------------------------------------------- set_eye

	void
	Camera::set_eye(const float x, const float y, const float z) 
	{
		eye.x = x; eye.y = y; eye.z = z;
	}

	// ----------------------------------------------------------------- set_lookat

	void
	Camera::set_lookat(const Point3D& p) 
	{
		lookat = p;
	}

	// ----------------------------------------------------------------- set_lookat

	void
	Camera::set_lookat(const float x, const float y, const float z) 
	{
		lookat.x = x; lookat.y = y; lookat.z = z;
	}

	// ----------------------------------------------------------------- set_up_vector

	void
	Camera::set_up_vector(const Vector3D& u) 
	{
		up = u;
	}

	// ----------------------------------------------------------------- set_up_vector
	void
	Camera::set_up_vector(const float x, const float y, const float z) 
	{
		up.x = x; up.y = y; up.z = z;
	}

	// ----------------------------------------------------------------- set_roll

	void
	Camera::set_roll(const float r) 
	{
		ra = r;
		compute_T_roll(1);
		compute_uvw();
	}

	void
	Camera::set_yaw(const float r)
	{
		ra = r;
		compute_T_roll(2);
		compute_uvw();
	}

	void 
	Camera::set_pitch(const float r)
	{
		ra = r;
		compute_T_roll(3);
		compute_uvw();
	}

	void
	Camera::compute_T_roll(int n)
	{
		Matrix T_p, T_minus_p, R_trans, R, Rz;
		T_p.set_identity();
		T_minus_p.set_identity();
		R_trans.set_identity();
		R.set_identity();
		Rz.set_identity();

		T_p.m[0][3] = (eye.x - lookat.x);
		T_p.m[1][3] = (eye.y - lookat.y);
		T_p.m[2][3] = (eye.z - lookat.z);

		T_minus_p.m[0][3] = -(eye.x - lookat.x);
		T_minus_p.m[1][3] = -(eye.y - lookat.y);
		T_minus_p.m[2][3] = -(eye.z - lookat.z);

		float ra_rads = (ra*M_PI) / 180;

		//rotation along the z direction
		if (n == 1)
		{
			Rz.m[0][0] = cos(ra_rads);
			Rz.m[0][1] = sin(ra_rads);
			Rz.m[1][0] = -sin(ra_rads);
			Rz.m[1][1] = Rz.m[0][0];
		} 
		//rotation along the x direction
		else if (n == 2)
		{
			Rz.m[1][1] = cos(ra_rads);
			Rz.m[1][2] = sin(ra_rads);
			Rz.m[2][1] = -sin(ra_rads);
			Rz.m[2][2] = cos(ra_rads);
		}
		//rotation along the y direction
		else if (n == 3)
		{
			Rz.m[0][0] = cos(ra_rads);
			Rz.m[0][2] = -sin(ra_rads);
			Rz.m[2][0] = sin(ra_rads);
			Rz.m[2][2] = cos(ra_rads);
		}

		R_trans.m[0][0] = u.x;
		R_trans.m[0][1] = v.x;
		R_trans.m[0][2] = w.x;
		R_trans.m[1][0] = u.y;
		R_trans.m[1][1] = v.y;
		R_trans.m[1][2] = w.y;
		R_trans.m[2][0] = u.z;
		R_trans.m[2][1] = v.z;
		R_trans.m[2][2] = w.z;

		R.m[0][0] = u.x;
		R.m[0][1] = u.y;
		R.m[0][2] = u.z;
		R.m[1][0] = v.x;
		R.m[1][1] = v.y;
		R.m[1][2] = v.z;
		R.m[2][0] = w.x;
		R.m[2][1] = w.y;
		R.m[2][2] = w.z;

		Matrix T = T_p*R_trans*Rz*R*T_minus_p;

		up = T*up;
	}

	// ----------------------------------------------------------------- set_exposure_time

	void
	Camera::set_exposure_time(const float exposure) 
	{
		exposure_time = exposure;
	}

	void
	Camera::render_stereo(Scene* w, float x, int offset)
	{}
}