#include <RegularSampler.h>

namespace RTFTGU
{
	// ---------------------------------------------------------------- default constructor

	RegularSampler::RegularSampler(void)
		: Sampler()
	{}


	// ---------------------------------------------------------------- constructor

	RegularSampler::RegularSampler(const int num)
		: Sampler(num)
	{
		generate_samples();
	}

	// ---------------------------------------------------------------- destructor			

	RegularSampler::~RegularSampler()
	{}

	// ---------------------------------------------------------------- generate_samples	

	void
	RegularSampler::generate_samples(void) 
	{
		int n = (int)sqrt((float)num_samples);

		for (int j = 0; j < num_sets; j++)
			for (int p = 0; p < n; p++)
				for (int q = 0; q < n; q++)
					samples.push_back(Point2D((q + 0.5) / n, (p + 0.5) / n));
	}

}