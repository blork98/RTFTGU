#ifndef SHADEREC_H_
#define SHADEREC_H_

#include <Point3D.h>
#include <Ray.h>
#include <RGB.h>
#include <Normal.h>

#include <memory>

namespace RTFTGU
{
	class Scene;
	class Material;

	class ShadeRec
	{
		public:
			bool				hit_an_object;		// did the ray hit an object?
			
			Point3D				hit_point;
			Point3D				local_hit_point;	// world coordinates of hit point 
			Normal				normal;				// normal at hit point
			Ray					ray;
			int					depth;
			RGBColor			color;				// used in Chapter 3 only
			const Scene&		w;					// world reference for shading	
			double				t;
			
			std::shared_ptr<Material> material_ptr;

			ShadeRec(const Scene& scene);				// constructor
			//ShadeRec(const std::shared_ptr<Scene> scene);
			ShadeRec(const ShadeRec& sr);				// copy constructor
			~ShadeRec(void);
	};
}

#endif