#include <ViewPlane.h>

#include <Sampler.h>
#include <MultiJitteredSampler.h>
#include <RegularSampler.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------- default constructor	

	ViewPlane::ViewPlane()
		: hres(400),
		vres(400),
		s(1.0),
		gamma(1.0),
		inv_gamma(1.0),
		show_out_of_gamut(false),
		num_samples(1),
		sampler_ptr(nullptr),
		max_depth(1)
	{}


	// ---------------------------------------------------------------- copy constructor

	ViewPlane::ViewPlane(const ViewPlane& vp)
		: hres(vp.hres),
		vres(vp.vres),
		s(vp.s),
		gamma(vp.gamma),
		inv_gamma(vp.inv_gamma),
		show_out_of_gamut(vp.show_out_of_gamut),
		num_samples(vp.num_samples),
		sampler_ptr(vp.sampler_ptr),
		max_depth(vp.max_depth)
	{}

	// -------------------------------------------------------------- destructor

	ViewPlane::~ViewPlane(void)
	{}

	// ------------------------------------------------------------------------------ set_hres

	void ViewPlane::set_hres(const int h_res) 
	{
		hres = h_res;
	}

	// ------------------------------------------------------------------------------ set_vres

	void ViewPlane::set_vres(const int v_res) 
	{
		vres = v_res;
	}

	// ------------------------------------------------------------------------------ set_pixel_size

	void ViewPlane::set_pixel_size(const float size) 
	{
		s = size;
	}

	// ------------------------------------------------------------------------------ set_gamma

	void ViewPlane::set_gamma(const float g) 
	{
		gamma = g;
		inv_gamma = 1.0 / gamma;
	}

	// ------------------------------------------------------------------------------ set_gamut_display

	void ViewPlane::set_gamut_display(const bool show) 
	{
		show_out_of_gamut = show;
	}

	//------------------sampler function
	void ViewPlane::set_sampler(std::shared_ptr<Sampler> sp)
	{
		num_samples = sp->get_num_samples();
		sampler_ptr = sp;
	}

	void ViewPlane::set_samples(const int n)
	{
		num_samples = n;

		if (num_samples > 1)
			sampler_ptr = std::make_shared<MultiJitteredSampler>(num_samples);
		else
			sampler_ptr = std::make_shared<RegularSampler>(1);
	}
}