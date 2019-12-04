#ifndef JITTERED_SAMPLER_H_
#define JITTERED_SAMPLER_H_

#include <Sampler.h>

namespace RTFTGU
{
	class JitteredSampler : public Sampler
	{
		public:
			JitteredSampler();
			JitteredSampler(const int num);
			~JitteredSampler();

			virtual void generate_samples();
	};
}

#endif