#ifndef VIEW_PLANE_H_
#define VIEW_PLANE_H_

#include <memory>

namespace RTFTGU
{
	class Sampler;

	class ViewPlane
	{
		public:
			int 			hres;   					// horizontal image resolution 
			int 			vres;   					// vertical image resolution
			float			s;							// pixel size

			float			gamma;						// gamma correction factor
			float			inv_gamma;					// the inverse of the gamma correction factor
			bool			show_out_of_gamut;			// display red if RGBColor out of gamut

			int				num_samples;				//samples per pixel for aliasing
			std::shared_ptr<Sampler> sampler_ptr;
			int				max_depth;					//initialize this to what??

			ViewPlane();   								// default Constructor
			ViewPlane(const ViewPlane& vp);				// copy constructor
			~ViewPlane();   							// destructor

			void set_hres(const int h_res);
			void set_vres(const int v_res);
			void set_pixel_size(const float size);
			void set_gamma(const float g);
			void set_gamut_display(const bool show);

			void set_sampler(std::shared_ptr<Sampler> sp);
			void set_samples(const int n);
			
	};
}

#endif