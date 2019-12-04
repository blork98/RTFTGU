#ifndef RANDOM_SAMPLER_H_
#define RANDOM_SAMPLER_H_

#include <Sampler.h>

namespace RTFTGU
{
	class RandomSampler : public Sampler
	{
		public:
			RandomSampler();
			RandomSampler(const int num);
			~RandomSampler();

			virtual void generate_samples();
	};
}

#endif