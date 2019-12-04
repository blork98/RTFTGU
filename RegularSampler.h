#ifndef REGULAR_SAMPLER_H_
#define REGULAR_SAMPLER_H_

#include<Sampler.h>

namespace RTFTGU
{
	class RegularSampler : public Sampler
	{
		public:
			RegularSampler();
			RegularSampler(const int num);
			virtual ~RegularSampler(void);

			virtual void generate_samples(void);
	};
}

#endif