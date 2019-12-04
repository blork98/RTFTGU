#include <FishEyeCamera.h>

#include <MathUtils.h>
#include <ViewPlane.h>
#include <Scene.h>
#include <Sampler.h>

#include <cmath>

namespace RTFTGU
{
	FishEyeCamera::FishEyeCamera()
		:Camera(),
		psi_max(0.0)
	{}

	FishEyeCamera::FishEyeCamera(float view_field)
		: Camera(),
		psi_max(view_field)
	{}

	FishEyeCamera::~FishEyeCamera()
	{}

	void
	FishEyeCamera::set_view_field(float psi_max_)
	{
		psi_max = psi_max_;
	}

	Vector3D
	FishEyeCamera::ray_direction(const Point2D& pp, const int hres,
			const int vres, const float s, float& r) const
	{
		Point2D pn((2.0*pp.x) / (s*hres), (2.0*pp.y) / (s*vres));
		r = pn.x*pn.x + pn.y*pn.y;

		if (r <= 1.0)
		{
			float r_sqrt = sqrt(r);
			float psi = r*psi_max*PI_ON_180;
			float sin_psi = sin(psi);
			float cos_psi = cos(psi);
			float sin_alpha = pn.y / r;
			float cos_alpha = pn.x / r;
			Vector3D dir = sin_psi*cos_alpha*u +
				sin_psi*sin_alpha*v -
				cos_psi*w;

			return dir;
		}
		else
		{
			return Vector3D(0.0);
		}
	}

	void
	FishEyeCamera::render_scene(Scene* w)
	{
		RGBColor L;
		ViewPlane vp(w->vp);

		Ray ray;
		int depth = 0;
		Point2D sp;
		Point2D pp;
		float r_squared = 0.0;

		ray.o = eye;

		for (int r = 0; r < vp.vres; r++)			// up
			for (int c = 0; c < vp.hres; c++)		// across
			{
				L = black;

				for (int j = 0; j < vp.num_samples; ++j)
				{
					sp = vp.sampler_ptr->sample_unit_square();
					pp.x = vp.s*(c - 0.5*vp.hres + sp.x);
					pp.y = vp.s*(r - 0.5*vp.vres + sp.y);

					ray.d = ray_direction(pp, vp.hres, vp.vres, vp.s, r_squared);

					if (r_squared <= 1.0)
						L += w->tracer_ptr->trace_ray(ray, depth);
				}

				L /= vp.num_samples;
				L *= exposure_time;
				w->display_pixel(r, c, L);
			}
	}

	void 
	FishEyeCamera::set_view_direction(const Vector3D& dir, double d)
	{
		//compute lookat
		//double length = std::sqrt(dir.x*dir.x +dir.y*dir.y+dir.z*dir.z);
		Vector3D normVec = dir;
		normVec.normalize();

		lookat.x = eye.x + d*normVec.x;
		lookat.y = eye.y + d*normVec.y;
		lookat.z = eye.z + d*normVec.z;
	}
}