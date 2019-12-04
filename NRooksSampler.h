#ifndef NROOKS_SAMPLER_H_
#define NROOKS_SAMPLER_H_

#include <Sampler.h>

namespace RTFTGU
{
	class NRooksSampler : public Sampler
	{
		NRooksSampler();
		NRooksSampler(const int num);
		~NRooksSampler();

		virtual void generate_samples();
	};
}

#endif