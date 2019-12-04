#include <Image.h>

#include <assert.h>

namespace RTFTGU
{
	Image::Image()
	{}

	Image::Image(int w_, int h_)
		:w(w_), h(h_)
	{
		assert(w > 0 && h > 0);
		raster = std::vector<std::vector<RGBColor>>(h, std::vector<RGBColor>(w));
	}

	Image::Image(int w_, int h_, RGBColor c)
		:w(w_), h(h_)
	{
		assert(w > 0 && h > 0);
		raster = std::vector<std::vector<RGBColor>>(h, std::vector<RGBColor>(w, c));
	}

	bool Image::set_pixel(int row, int col, const RGBColor& c)
	{
		if (col >= 0 && col < w && row >= 0 && row < h)
		{
			//raster[col][row] = c;
			raster[row][col] = c;
			return true;
		}

		return false;
	}

	RGBColor 
	Image::get_pixel(int x, int y) const
	{
		x = (x >= 0 ? x : 0);
		x = (x <  w ? x : w - 1);
		y = (y >= 0 ? y : 0);
		y = (y <  h ? y : h - 1);

		return raster[y][x];
	}

	void 
	Image::writePPM(std::ostream& s) const
	{
		s << "P6\n" << w << " " << h << "\n255\n";

		unsigned int ired, igreen, iblue;

		//output clamped [0,255]
		//for (int y = h - 1; y >= 0; y--)
		for (int y = 0; y < h;y++)
			for (int x = 0; x < w; x++)
			{
				ired = (unsigned int)(256.0 * raster[y][x].r);
				if (ired > 255) ired = 255;
				s.put((unsigned char)ired);

				igreen = (unsigned int)(256.0 * raster[y][x].g);
				if (igreen > 255) igreen = 255;
				s.put((unsigned char)igreen);

				iblue = (unsigned int)(256.0 * raster[y][x].b);
				if (iblue > 255) iblue = 255;
				s.put((unsigned char)iblue);
			}
	}

}