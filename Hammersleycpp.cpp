#include <HammerslySampler.h>

namespace RTFTGU
{
	Hammersley::Hammersley()
		: Sampler()
	{}

	Hammersley::Hammersley(const int num)
		: Sampler(num)
	{
		generate_samples();
	}

	Hammersley::~Hammersley()
	{}

	void Hammersley::generate_samples(void)
	{
		for (int p = 0; p < num_sets; ++p)
			for (int j = 0; j < num_samples; ++j)
			{
				samples.push_back(Point2D((float)j / (float)num_samples, phi(j)));
			}
	}

	double Hammersley::phi(int j) const
	{
		double x = 0.0;
		double f = 0.5;

		while (j)
		{
			x += f * (double)(!j & 1);
			j /= 2;
			f *= 0.5;
		}

		return x;
	}

}