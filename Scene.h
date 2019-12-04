#ifndef SCENE_H_
#define SCENE_H_

#include <ViewPlane.h>
#include <RGB.h>
#include <Sphere.h>
#include <Tracer.h>
#include <GeometricObject.h>
#include <Camera.h>
#include <Light.h>

#include <memory>
#include <vector>

namespace RTFTGU
{
	class Scene
	{
		public:
			ViewPlane vp;
			RGBColor background_color;
			Sphere sphere;

			double	eye, d;

			std::vector<std::shared_ptr<GeometricObject>>	objects;
			std::shared_ptr<Tracer> tracer_ptr;
			std::shared_ptr<Camera> camera_ptr;
			std::shared_ptr<Light> ambient_ptr;
			std::vector<std::shared_ptr<Light>> lights;

			Scene();
			virtual ~Scene();

			void add_object(std::shared_ptr<GeometricObject> object_ptr);
			void add_light(std::shared_ptr<Light> light);

			virtual void build() = 0;
			virtual void set_pixel(int x, int y, const RGBColor& color) = 0;
			virtual void display_pixel(const int row, const int column, const RGBColor& pixel_color);
			virtual void render_scene();
			virtual void render_perspective();
			void set_ambient_light(std::shared_ptr<Light> light);

			RGBColor max_to_one(const RGBColor& c) const;
			RGBColor clamp_to_color(const RGBColor& c) const;

			ShadeRec hit_bare_bones_objects(const Ray& ray);
			ShadeRec hit_objects(const Ray& ray);
			
	};
}

#endif