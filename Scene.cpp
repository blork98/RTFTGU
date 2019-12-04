#include <Scene.h>

#include <Constants.h>
#include <Point3D.h>
#include <Point2D.h>
#include <MathUtils.h>
#include <Sampler.h>
#include <AmbientLight.h>

namespace RTFTGU
{
	// -------------------------------------------------------------------- default constructor

	Scene::Scene()
		: background_color(black),
		eye(0.0),d(0.0)
	{
		ambient_ptr = std::make_shared<AmbientLight>();
	}

	Scene::~Scene(void) 
	{}

	void
	Scene::render_scene() 
	{

		RGBColor	pixel_color;
		Ray			ray;
		int 		hres = vp.hres;
		int 		vres = vp.vres;
		float		s = vp.s;
		float		zw = 100.0;			// hardwired in
		double x, y;

		ray.d = Vector3D(0, 0, -1);

		Point2D sp;
		Point2D pp;

		for (int r = 0; r < vres; r++)			// up
			for (int c = 0; c <= hres; c++) 	// across 
			{
				pixel_color = black;

				for (int j = 0; j < vp.num_samples; j++)
				{
					sp = vp.sampler_ptr->sample_unit_square();
					pp.x = vp.s*(c - 0.5*vp.hres +sp.x);
					pp.y = vp.s*(r - 0.5*vp.vres +sp.y);
					ray.o = Point3D(pp.x, pp.y, zw);

					pixel_color += tracer_ptr->trace_ray(ray);
				}

				pixel_color /= vp.num_samples;
				display_pixel(r, c, pixel_color);
			}
	}

	void 
	Scene::render_perspective()
	{
		RGBColor	pixel_color;
		Ray			ray;

		ray.o = Point3D(0.0, 0.0, eye);

		for (int r = 0; r < vp.vres; ++r)
			for (int c = 0; c < vp.hres; ++c)
			{
				ray.d = Vector3D(vp.s*(c - 0.5*(vp.hres - 1.0)),
					vp.s*(r - 0.5*(vp.vres - 1.0)), -d);
				ray.d.normalize();
				pixel_color = tracer_ptr->trace_ray(ray);
				display_pixel(r, c, pixel_color);
			}
	}

	RGBColor
	Scene::max_to_one(const RGBColor& c) const 
	{
		float max_value = max(c.r, max(c.g, c.b));

		if (max_value > 1.0)
			return (c / max_value);
		else
			return (c);
	}

	RGBColor
	Scene::clamp_to_color(const RGBColor& raw_color) const 
	{
		RGBColor c(raw_color);

		if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
			c.r = 1.0; c.g = 0.0; c.b = 0.0;
		}

		return (c);
	}

	void
	Scene::display_pixel(const int row, const int column, const RTFTGU::RGBColor& pixel_color)
	{
		RGBColor mapped_color;

		if (vp.show_out_of_gamut)
			mapped_color = clamp_to_color(pixel_color);
		else
			mapped_color = max_to_one(pixel_color);

		if (vp.gamma != 1.0)
			mapped_color = mapped_color.powc(vp.inv_gamma);

		//have to start from max y coordinate to convert to screen coordinates
		int x = column;
		int y = vp.vres - row - 1;
		//int y = row;

		//set_pixel(x, y, 
		//	(int)(mapped_color.r * 255),
		//	(int)(mapped_color.g * 255),
		//	(int)(mapped_color.b * 255));
		set_pixel(y, x, mapped_color);
	}

	ShadeRec
	Scene::hit_bare_bones_objects(const Ray& ray) 
	{
		ShadeRec	sr(*this);
		double		t;
		float		tmin = kHugeValue;
		int 		num_objects = objects.size();

		for (int j = 0; j < num_objects; j++)
			if (objects[j]->hit(ray, t, sr) && (t < tmin)) 
			{
				sr.hit_an_object = true;
				tmin = t;
				sr.color = objects[j]->get_color();
			}

		return (sr);
	}

	void
	Scene::add_object(std::shared_ptr<GeometricObject> object_ptr) 
	{
		objects.push_back(object_ptr);
	};

	void
	Scene::add_light(std::shared_ptr<Light> light)
	{
		lights.push_back(light);
	}

	void 
	Scene::set_ambient_light(std::shared_ptr<Light> light)
	{
		ambient_ptr = light;
	}

	ShadeRec
	Scene::hit_objects(const Ray& ray)
	{

		ShadeRec	sr(*this);
		double		t;
		Normal		normal;
		Point3D		local_hit_point;
		double		tmin = kHugeValue;
		int 		num_objects = objects.size();

		for (int j = 0; j < num_objects; j++)
			if (objects[j]->hit(ray, t, sr) && (t < tmin)) 
			{
				sr.hit_an_object = true;
				tmin = t;
				sr.material_ptr = objects[j]->get_material(); //added this
				sr.hit_point = ray.o + t * ray.d;
				normal = sr.normal;
				local_hit_point = sr.local_hit_point;
			}

		if (sr.hit_an_object) 
		{
			sr.t = tmin;
			sr.normal = normal;
			sr.local_hit_point = local_hit_point;
		}

		return(sr);
	}
}