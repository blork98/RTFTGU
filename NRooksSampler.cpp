#include <NRooksSampler.h>

namespace RTFTGU
{

	NRooksSampler::NRooksSampler(void)
		:Sampler()
	{}

	NRooksSampler::NRooksSampler(const int num)
		: Sampler(num)
	{
		generate_samples();
	}

	NRooksSampler::~NRooksSampler()
	{}

	void  
	NRooksSampler::generate_samples(void)
	{
		for (int p = 0; p < num_sets; ++p)
			for (int j = 0; j < num_samples; ++j)
			{
				samples.push_back(
					Point2D((j + rand_float()) / num_samples,
						(j + rand_float()) / num_samples));
			}

		shuffle_x_coordinates();
		shuffle_y_coordinates();

	}
}