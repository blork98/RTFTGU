#ifndef SPHERE_H_
#define SPHERE_H_

#include <GeometricObject.h>
#include <ShadeRec.h>

namespace RTFTGU
{
	class Sphere : public GeometricObject
	{
		public:
			Sphere(void);   									// Default constructor
			Sphere(Point3D center, double r);					// Constructor 
			Sphere(const Sphere& sphere); 						// Copy constructor

			virtual ~Sphere(void);								// Destructor
			
			void set_center(const Point3D& c);
			void set_center(const double x, const double y, const double z);
			void set_radius(const double r);

			virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;
			bool shadow_hit(const Ray& ray, double& tmin) const;

		private:

			Point3D 	center;   			// center coordinates as a point  
			double 		radius;				// the radius 
	};
}

#endif