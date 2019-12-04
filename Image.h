#ifndef IMAGE_H_
#define IMAGE_H_

#include <RGB.h>
#include <vector>
#include <iostream>

namespace RTFTGU
{
	class Image
	{
		public:
			Image();
			Image(int w, int h);
			Image(int w, int h, RGBColor c);

			bool set_pixel(int x, int y, const RGBColor& c);
			RGBColor get_pixel(int x, int y) const;

			int width()  const;
			int height() const;

			void writePPM(std::ostream& s) const;

		private:
			int w, h;
			std::vector<std::vector<RGBColor>> raster;
	};
}

#endif