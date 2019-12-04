#include <Point2D.h>

namespace RTFTGU
{
	// ------------------------------------------------ default constructor

	Point2D::Point2D()
		: x(0.0), y(0.0)
	{}


	// ------------------------------------------------ constructor

	Point2D::Point2D(const float arg)
		: x(arg), y(arg)
	{}

	// ------------------------------------------------ constructor

	Point2D::Point2D(const float x1, const float y1)
		: x(x1), y(y1)
	{}


	// ------------------------------------------------ copy constructor

	Point2D::Point2D(const Point2D& p)
		: x(p.x), y(p.y)
	{}

	// ------------------------------------------------ destructor

	Point2D::~Point2D(void) 
	{}

	Point2D
	Point2D::operator* (const float a) 
	{
		return (Point2D(x * a, y * a));
	}
}