#ifndef POINT2D_H_
#define POINT2D_H_

namespace RTFTGU
{
	class Point2D
	{
		public:
			float x, y;

			Point2D();
			Point2D(const float arg);
			Point2D(const float x1, const float y1);
			Point2D(const Point2D& p);
			~Point2D(void);

			Point2D operator* (const float a);
	};
}

#endif