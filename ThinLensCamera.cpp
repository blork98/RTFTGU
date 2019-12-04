#include <ThinLensCamera.h>

#include <Ray.h>
#include <Scene.h>
#include <ViewPlane.h>

namespace RTFTGU
{
	ThinLensCamera::ThinLensCamera()
		: Camera(),
		lens_radius(0.0),
		d(0.0),
		f(0.0),
		zoom(0.0)
	{}

	ThinLensCamera::~ThinLensCamera()
	{}

	void 
	ThinLensCamera::set_sampler(std::shared_ptr<Sampler> sp)
	{
		sampler_ptr = sp;
		sampler_ptr->map_samples_to_unit_disk();
	}


	Vector3D
	ThinLensCamera::ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const
	{
		Point2D p;
		p.x = pixel_point.x*f / d;
		p.y = pixel_point.y*f / d;

		Vector3D dir = (p.x - lens_point.x)*u + (p.y - lens_point.y)*v - f*w;
		dir.normalize();

		return dir;
	}

	void
	ThinLensCamera::render_scene(Scene* w)
	{
		RGBColor L;
		Ray ray;
		ViewPlane vp(w->vp);
		int depth = 0;

		Point2D sp;
		Point2D pp;
		Point2D dp;
		Point2D lp;

		vp.s /= zoom;

		for (int r = 0; r < vp.vres; r++)			// up
			for (int c = 0; c < vp.hres; c++)		// across
			{
				L = black;

				for (int j = 0; j < vp.num_samples; ++j)
				{
					sp = vp.sampler_ptr->sample_unit_square();
					pp.x = vp.s*(c - 0.5*vp.hres + sp.x);
					pp.y = vp.s*(r - 0.5*vp.vres + sp.y);

					dp = sampler_ptr->sample_unit_disk();
					lp = dp*lens_radius;

					ray.o = eye + lp.x*u + lp.y*v;
					ray.d = ray_direction(pp, lp);
					L += w->tracer_ptr->trace_ray(ray, depth);
				}

				L /= vp.num_samples;
				L *= exposure_time;
				w->display_pixel(r, c, L);
			}

	}
}