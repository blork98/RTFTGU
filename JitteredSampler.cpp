#include <JitteredSampler.h>

#include <MathUtils.h>

namespace RTFTGU
{
	JitteredSampler::JitteredSampler()
		:Sampler()
	{}

	JitteredSampler::JitteredSampler(const int num)
		: Sampler(num)
	{
		generate_samples();
	}

	JitteredSampler::~JitteredSampler()
	{}

	void JitteredSampler::generate_samples(void)
	{
		int n = (int)sqrt((float)num_samples);

		for (int p = 0; p < num_sets; ++p)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
				{
					samples.push_back(
						Point2D((k + rand_float()) / n, (j + rand_float()) / n));
				}
	}
}