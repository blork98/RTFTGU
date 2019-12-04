#include <RandomSampler.h>

#include <MathUtils.h>

namespace RTFTGU
{
	RandomSampler::RandomSampler()
		:Sampler()
	{}

	RandomSampler::RandomSampler(const int num)
		: Sampler(num)
	{
		generate_samples();
	}

	RandomSampler::~RandomSampler()
	{}

	void RandomSampler::generate_samples(void)
	{
		for (int p = 0; p < num_sets; p++)
			for (int q = 0; q < num_samples; q++)
				samples.push_back(Point2D(rand_float(), rand_float()));
	}

}