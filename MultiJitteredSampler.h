#ifndef MULTIJITTERED_SAMPLER_H_
#define MULTIJITTERED_SAMPLER_H_

#include <Sampler.h>

namespace RTFTGU
{
	class MultiJitteredSampler : public Sampler
	{
		public:
			MultiJitteredSampler();
			MultiJitteredSampler(const int num_samples);
			MultiJitteredSampler(const int num_samples, const int m);
			~MultiJitteredSampler();

			virtual void generate_samples(void);

	};
}

#endif