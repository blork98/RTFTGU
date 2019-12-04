#include <StereoCamera.h>

#include <MathUtils.h>
#include <ViewPlane.h>
#include <Scene.h>
#include <Sampler.h>
#include <cmath>

namespace RTFTGU
{
	StereoCamera::StereoCamera()
		: Camera(),
		viewing(parallel),
		pixel_gap(0),
		beta(0.0)
	{}

	StereoCamera::~StereoCamera()
	{}

	void
	StereoCamera::set_left_camera(std::shared_ptr<Camera> left)
	{
		left_camera_ptr = left;
	}

	void
	StereoCamera::set_right_camera(std::shared_ptr<Camera> right)
	{
		right_camera_ptr = right;
	}

	void
	StereoCamera::set_viewing(ViewingType viewing)
	{
		this->viewing = viewing;
	}

	void
	StereoCamera::set_pixel_gap(int pix_gap)
	{
		pixel_gap = pix_gap;
	}

	void
	StereoCamera::set_beta(float beta)
	{
		this->beta = beta;
	}

	void
	StereoCamera::setup_cameras()
	{
		float r = eye.distance(lookat);
		float x = r*tan(0.5*beta*PI_ON_180);

		left_camera_ptr->set_eye(eye - x*u);
		left_camera_ptr->set_lookat(lookat - x*u);
		left_camera_ptr->compute_uvw();

		right_camera_ptr->set_eye(eye + x*u);
		right_camera_ptr->set_lookat(lookat + x*u);
		right_camera_ptr->compute_uvw();
	}

	void
	StereoCamera::render_scene(Scene* w)
	{
		const ViewPlane& vp = w->vp;
		const int& hres = vp.hres;
		const int& vres = vp.vres;

		float r = eye.distance(lookat);
		float x = r*tan(0.5*beta*PI_ON_180);

		if (viewing == parallel)
		{
			left_camera_ptr->render_stereo(w, x, 0);
			right_camera_ptr->render_stereo(w, -x, hres + pixel_gap);
		}
		else
		{
			right_camera_ptr->render_stereo(w, -x, 0);
			left_camera_ptr->render_stereo(w, x, hres + pixel_gap);
		}

	}
	
}