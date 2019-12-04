#include <SphericalCamera.h>

#include <MathUtils.h>
#include <ViewPlane.h>
#include <Scene.h>
#include <Sampler.h>

#include <cmath>

namespace RTFTGU
{
	SphericalCamera::SphericalCamera()
		:Camera()
	{}

	SphericalCamera::SphericalCamera(float view_field_vertical,
		float view_field_horizontal)
		: Camera(),
		psi_max(view_field_vertical),
		lambda_max(view_field_horizontal)
	{}

	SphericalCamera::~SphericalCamera()
	{}

	void
	SphericalCamera::set_view_field_vertical(float psi_max_)
	{
		psi_max = psi_max_;
	}

	void
	SphericalCamera::set_view_field_horizontal(float lambda_max_)
	{
		lambda_max = lambda_max_;
	}

	Vector3D
	SphericalCamera::ray_direction(const Point2D& pp, const int hres,
			const int vres, const float s) const
	{
		Point2D pn((2.0*pp.x) / (s*hres), (2.0*pp.y) / (s*vres));

		float lambda = pn.x * lambda_max * PI_ON_180;
		float psi = pn.y * psi_max * PI_ON_180;

		float phi = PI - lambda;
		float theta = 0.5*PI - psi;

		float sin_phi = sin(phi);
		float cos_phi = cos(phi);
		float sin_theta = sin(theta);
		float cos_theta = cos(theta);

		Vector3D dir = sin_theta*sin_phi*u + cos_theta*v +
			sin_theta*cos_phi * w;

		return dir;
	}

	void
	SphericalCamera::render_scene(Scene* w)
	{

		RGBColor L;
		ViewPlane vp(w->vp);

		Ray ray;
		int depth = 0;
		Point2D sp;
		Point2D pp;

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

					ray.d = ray_direction(pp, vp.hres, vp.vres, vp.s);

					L += w->tracer_ptr->trace_ray(ray, depth);
				}

				L /= vp.num_samples;
				L *= exposure_time;
				w->display_pixel(r, c, L);
			}
	}
}