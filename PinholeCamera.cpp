#include <PinholeCamera.h>

#include <ViewPlane.h>
#include <Sampler.h>
#include <Constants.h>
#include <Point3D.h>
#include <Vector3D.h>
#include <Ray.h>
#include <cmath>

namespace RTFTGU
{
	PinholeCamera::PinholeCamera()
		: Camera(),
		d(500),
		zoom(1.0)
	{}

	PinholeCamera::~PinholeCamera()
	{}

	Vector3D
	PinholeCamera::get_direction(const Point2D& p) const
	{
		Vector3D dir = p.x * u + p.y * v - d * w;
		dir.normalize();

		return(dir);
	}

	void
	PinholeCamera::set_view_distance(float _d) 
	{
		d = _d;
	}

	void
	PinholeCamera::set_zoom(float zoom_factor) 
	{
		zoom = zoom_factor;
	}

	void
	PinholeCamera::render_scene(Scene* w)
	{
		RGBColor	L;
		ViewPlane	vp(w->vp);
		
		Ray			ray;
		int 		depth = 0;
		Point2D 	pp;		// sample point on a pixel
		Point2D		sp;		//sample point in [0,1] x [0,1]
		int n = (int)sqrt((float)vp.num_samples);

		vp.s /= zoom;
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
					ray.d = get_direction(pp);
					L += w->tracer_ptr->trace_ray(ray, depth);
				}

				L /= vp.num_samples;
				L *= exposure_time;
				w->display_pixel(r, c, L);
			}
			
	}

	void
	PinholeCamera::render_stereo(Scene* w, float x, int offset)
	{
		RGBColor L;
		Ray ray;
		ViewPlane vp = w->vp;
		int depth = 0;
		Point2D sp;
		Point2D pp;

		vp.s /= zoom;
		ray.o = eye;

		for (int r = 0; r < vp.vres; r++)			// up
			for (int c = 0; c < vp.hres; c++)		// across
			{
				L = black;

				for (int j = 0; j < vp.num_samples; ++j)
				{
					sp = vp.sampler_ptr->sample_unit_square();
					pp.x = vp.s*(c - 0.5*vp.hres + sp.x) + x;
					pp.y = vp.s*(r - 0.5*vp.vres + sp.y);

					ray.d = get_direction(pp);
					L += w->tracer_ptr->trace_ray(ray, depth);
				}

				L /= vp.num_samples;
				L *= exposure_time;
				w->display_pixel(r, c + offset, L);
			}
	}
	
}